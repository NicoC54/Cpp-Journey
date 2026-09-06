#include <iostream>
#include <ctime>


int main() {



    srand(time(NULL));

    int num1 =(rand() % 6) + 1;
    int num2 =(rand() % 6) + 1;
    int num3 =(rand() % 6) + 1;


    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

   return 0 ;
}


