#include <iostream>

enum Day {sunday = 0,monday = 1};

enum Flavor {vanilla, chocolate, strawberry, mint};

int main() {

    Day today = monday;

    switch(today){
        case sunday: std::cout << "It is Sunday!";
                       break;
  
        case monday: std::cout << "It is Monday!";
                       break;
    }
   
    return 0;
}

