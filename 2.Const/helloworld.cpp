#include <iostream>


int main() {

    const double PI = 3.14159;
    //PI = 420.69; //we try to change this value
    double radius = 10;
    double circumference = 2 * PI * radius;

    const int LIGHT_SPEED = 300000000;
    const int WIDTH = 2000;

    std::cout << circumference << " cm" <<std::endl;
    std::cout << LIGHT_SPEED << " m/s" <<std::endl;
    std::cout << WIDTH << " cm" <<std::endl;

    return 0;

}