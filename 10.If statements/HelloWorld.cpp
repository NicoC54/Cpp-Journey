#include <iostream>
#include <cmath>

int main() {

    int age;

    std::cout << "Enter your age " << std::endl;
    std::cin >> age;


    if (age>=100){
        std::cout << "you are too old" << std::endl;
    }

    else if (age >= 18){
        std::cout << "you are an adult" << std::endl;
    }

    else if (age < 0){
        std::cout << "you are not born" << std::endl;

    }

    else{
        std::cout << "you are a kid" << std::endl;

    }
    return 0;

}

