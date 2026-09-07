#include <iostream>


int main() {


    std::cout << sizeof(double)<< std::endl;

    std::cout << sizeof(std::string)<< std::endl;

    std::cout << sizeof(char)<< std::endl;

    std::cout << sizeof(bool)<< std::endl;

    char grades[] = {'A','B','C'};

    std::cout << sizeof(grades) << std::endl;

    std::string students[] = {"Spongebob", "Patrick"};

    std::cout << sizeof(students) << std::endl;

    return 0;
}
