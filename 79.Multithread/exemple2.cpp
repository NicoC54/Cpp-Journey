#include <iostream>
#include <thread>
#include <map>
#include <chrono>
using namespace std::chrono_literals;


void RefreshForecast(std::map<std::string,double> forecastMap){

    while(true){

    for (auto& pair : forecastMap){
        pair.second++;
        std::cout <<pair.first <<" - " << pair.second <<std::endl;

    }
    std::this_thread::sleep_for(2000ms);

}
}

int main()
{

    std::map<std::string,double> forecastMap = {
        {"New York",15},
        {"Mumbai",20},
        {"Berlin",18},
    };

    std::thread worker1(RefreshForecast,forecastMap);
    worker1.join();




}