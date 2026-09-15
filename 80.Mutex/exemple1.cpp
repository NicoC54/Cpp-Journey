#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex carMutex;



void driveCar(std::string driverName){
    std::lock_guard<std::mutex> lock(carMutex); // permet de bloquer à un thread la section critique
    std::cout << driverName << " is driving " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << driverName << " is done driving " << std::endl;
}

int main(){

    std::thread thread1(driveCar, "saldina");
    std::thread thread2(driveCar, "roberto");

    thread1.join();
    thread2.join();

}
