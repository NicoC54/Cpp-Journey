#include <iostream>
#include <cmath>

int main() {

    int sideA = 10;
    int sideB = 5;
    float hypothenuse = sqrt(pow(sideA,2) + pow(sideB,2));

    std::cout << "The hypothenuse is: " << hypothenuse << std::endl;

    return 0;

}

