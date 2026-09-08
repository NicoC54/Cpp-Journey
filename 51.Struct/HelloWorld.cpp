#include <iostream>
#include <ctime>

struct student{
    std::string name;
    double gpa;
    bool enrolled;
};


int main() {

    student student1;
    student1.name = "SpongeBob";
    student1.gpa = 3.2;
    student1.enrolled = true;


    student student2;
    student2.name = "Patrick";
    student2.gpa = 2.2;
    student2.enrolled = true;


    std::cout << student1.name << std::endl;
    std::cout << student1.gpa << std::endl;

    std::cout << student2.name << std::endl;
    std::cout << student2.gpa << std::endl;

    return 0;
}


