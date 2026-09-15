#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include <queue>

std::atomic<bool> emergency_stop = false;
std::atomic<int> telemetry_counter = 0;

struct DronePose{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

DronePose current_pose;
std::mutex pose_mutex;

void update_odometry(double nx, double ny, double nz){
    std::lock_guard<std::mutex> lock(pose_mutex); //cree un objet lock qui va lock pose mutex à sa creation et unlock lorsquil est detruit. si le mutex nest pas dispo de suite, on attend a cette ligne jsuqua quil soit dispo
    current_pose.x = nx;
    current_pose.y = ny;
    current_pose.z = nz;
}

//condition variable

std::condition_variable condition_variable;
std::queue<int> lidar_raw_frames;
std::mutex lidar_mutex;

void lidar_driver(){
    for (int i =0; i <3; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  
    {
        std::lock_guard<std::mutex> lock(lidar_mutex);
        lidar_raw_frames.push(i);
        std::cout << i << std::endl;
    }  
    
        condition_variable.notify_one();

}
}

void obstacle_avoidance(){
     for (int i = 0; i < 3; ++i) {
    std::unique_lock<std::mutex> lock(lidar_mutex);

    condition_variable.wait(lock, []{ return !lidar_raw_frames.empty() || emergency_stop.load();});

    if (emergency_stop.load()){
        break;}


    int frame = lidar_raw_frames.front();
        lidar_raw_frames.pop();
        lock.unlock(); // On peut libérer manuellement avant le traitement lourd

        std::cout << "[Évitement] Traitement de la trame LiDAR " << frame << '\n';
    }
}

std::mutex arm_mutex;
std::mutex gripper_mutex;

void grab_payload() {

    std::scoped_lock(arm_mutex,gripper_mutex); // necessite le lock sur le deux mutex pour tourner 
    std::cout << "[Bras] Verrous bras + pince acquis simultanement sans risque de deadlock\n";
}

int main() {
    std::cout << "--- Demarrage du systeme robotique ---\n";

    // Lancement des threads concurrents
    std::thread t_lidar(lidar_driver);
    std::thread t_avoidance(obstacle_avoidance);
    std::thread t_arm(grab_payload);

    // Boucle de contrôle rapide (ex. consigne d'attitude à haute fréquence)
    update_odometry(1.2, 0.4, 10.5);
    telemetry_counter.fetch_add(1);

    // Attente de la fin des tâches
    t_lidar.join();
    t_avoidance.join();
    t_arm.join();

    std::cout << "--- Fin de mission. Telemetrie envoyee : " << telemetry_counter.load() << " ---\n";
    return 0;
}