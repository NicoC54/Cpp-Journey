#include <iostream>


/*
class Student{
    public:
        std::string name;
        int age;
        double gpa;

    Student(std::string name, int age, double gpa){
        this->name = name;
        this->age = age;
        this->gpa = gpa;

    }


};
*/
class Car{
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;

        Car(std::string make, std::string model, int year, std::string color){
            this->make = make;
            this->model = model;
            this->year = year;
            this->color = color;
        }
};




int main() {

   Car ferrari("ferrari","f200",2025,"red");

   std::cout <<ferrari.year;




    return 0;
}

