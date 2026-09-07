#include <iostream>
#include <ctime>


void happyBirthday(std::string name, int age);




int main() {

    int age = 80;
    std::string name = "Bro";
    happyBirthday(name, age);

   return 0 ;
}


void happyBirthday(std::string name, int age){
    std::cout << "Happy Birthday to you " << name << " you are " << age << " years old '\n'" ;
}



