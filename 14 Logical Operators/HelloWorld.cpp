#include <iostream>
#include <cmath>

int main() {
    
    int temp;
    bool sunny = false;

    std::cout << "Enter the temperature";
    std::cin >> temp;
    

    if (temp >=0 && temp <30){
        std::cout << "the temperature is good!";
    }

    else{
        std::cout << "the temperature is bad!";
    }

    if(sunny){
        std::cout << "It is sunny outside";
    }

    else{
        std::cout << "It is cloudy outside";
    }
    return 0;

}

