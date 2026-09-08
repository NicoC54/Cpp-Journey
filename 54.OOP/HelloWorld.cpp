#include <iostream>



class Human{
    public:
        std::string name = "Rick";
        std::string occupation = "Scientist";
        int age = 70;

        void eat(){
            std::cout <<"This person is eating\n";
        }

        void drink(){
            std::cout <<"This person is eating\n";

        }
        void sleep(){
            std::cout << "This person is sleeping\n";
        }
};

class Car{
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;

        void accelerate(){
            std::cout << "You step on the gas\n";
        }
        void brake(){
            std::cout << "you just brake\n";
        }
};

int main() {

Human Nico;

Nico.name = "Nicolas";
Nico.occupation = "video games";
Nico.age = 23;

Human Natalia;

Natalia.name = "Natalia";
Natalia.occupation = "coffee";
Natalia.age = 25;

std::cout << Nico.name;
std::cout << Natalia.name;

Nico.eat();
Nico.sleep();

Human human2;

std::cout << human2.name <<std::endl;

Car car1;
car1.make = "Ford";
car1.model = "Mustang";
car1.year = 2026;
car1.color ="red";

car1.accelerate();
car1.brake();

  
    return 0;
}

