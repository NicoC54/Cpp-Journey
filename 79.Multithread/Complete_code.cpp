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
    std::lock_guard<std::mutex> lock(pose_mutex); //cree un objet lock qui va lock pose mutex à sa creation et unlock lorsquil est detruit
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
