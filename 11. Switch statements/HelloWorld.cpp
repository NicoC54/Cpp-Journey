#include <iostream>
#include <cmath>

int main() {

    int month;

    std::cout << "enter the month(1-2)";
    std::cin >> month;

    switch(month){
        case 1:
            std::cout<<"its january";
            break;
      
        case 2:
            std::cout << "its february";
            break;
           
        default:
            std::cout << "Please enter in only numers (1-12)";
            break;
            }


    return 0;

}

