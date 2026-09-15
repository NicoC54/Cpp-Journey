#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include <queue>

// ============================================================================
// 1. STD::ATOMIC : Variables simples "one-shot" sans verrou (Lock-free)
// ============================================================================
// Idéal pour un flag d'arrêt d'urgence lu à haute fréquence par les moteurs
std::atomic<bool> emergency_stop{false};
std::atomic<int> telemetry_counter{0};

// ============================================================================
// 2. RAII & STD::LOCK_GUARD : Protection de données complexes partagées
// ============================================================================
struct DronePose {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

DronePose current_pose;
std::mutex pose_mutex;

void update_odometry(double nx, double ny, double nz) {
    // RAII : pose_lock verrouille pose_mutex dès sa création.
    // Dès la sortie du scope {}, l'objet est détruit et déverrouille le mutex.
    std::lock_guard<std::mutex> pose_lock(pose_mutex);
    current_pose.x = nx;
    current_pose.y = ny;
    current_pose.z = nz;
} // Déverrouillage automatique garanti ici

// ============================================================================
// 3. STD::CONDITION_VARIABLE : Attente sans saturer le CPU (Producer / Consumer)
// ============================================================================
std::queue<int> lidar_raw_frames;
std::mutex lidar_mutex;
std::condition_variable lidar_cv;

// Thread 1 : Producteur (Driver du capteur LiDAR à ~10 Hz)
void lidar_driver_thread() {
    for (int frame_id = 1; frame_id <= 3; ++frame_id) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simule l'acquisition
        
        {
            std::lock_guard<std::mutex> lock(lidar_mutex);
            lidar_raw_frames.push(frame_id);
            std::cout << "[LiDAR] Trame " << frame_id << " acquise\n";
        }
        // Réveille le thread consommateur en attente
        lidar_cv.notify_one();
    }
}

// Thread 2 : Consommateur (Algorithme d'évitement d'obstacles)
void obstacle_avoidance_thread() {
    for (int i = 0; i < 3; ++i) {
        // std::unique_lock est requis par la condition_variable (plus souple que lock_guard)
        std::unique_lock<std::mutex> lock(lidar_mutex);

        // Mise en veille du thread : libère le mutex et attend sans consommer de CPU
        lidar_cv.wait(lock, [] { 
            return !lidar_raw_frames.empty() || emergency_stop.load(); 
        });

        if (emergency_stop.load()) break;

        int frame = lidar_raw_frames.front();
        lidar_raw_frames.pop();
        lock.unlock(); // On peut libérer manuellement avant le traitement lourd

        std::cout << "[Évitement] Traitement de la trame LiDAR " << frame << '\n';
    }
}

// ============================================================================
// 4. STD::SCOPED_LOCK : Évitement systématique du Deadlock
// ============================================================================
std::mutex arm_mutex;
std::mutex gripper_mutex;

void grab_payload() {
    // Acquiert les deux verrous de manière atomique et ordonnée.
    // Même si un autre thread verrouille gripper_mutex et arm_mutex dans l'ordre inverse,
    // scoped_lock empêche l'interblocage (deadlock).
    std::scoped_lock lock(arm_mutex, gripper_mutex);
    std::cout << "[Bras] Verrous bras + pince acquis simultanement sans risque de deadlock\n";
}

// ============================================================================
// MAIN : Orchestration des threads
// ============================================================================
int main() {
    std::cout << "--- Demarrage du systeme robotique ---\n";

    // Lancement des threads concurrents
    std::thread t_lidar(lidar_driver_thread);
    std::thread t_avoidance(obstacle_avoidance_thread);
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