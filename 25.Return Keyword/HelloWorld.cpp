#include <iostream>

double areacalculator(double length);

double volumecalculator(double length);

std::string fullName(std::string first_Name, std::string last_Name);




int main() {

    double length = 5;
    double area = areacalculator(length);
    double volume = volumecalculator(length);
    std::string first_Name = "Nicolas";
    std::string last_Name = "Consalvi";
    std::string name = fullName(first_Name, last_Name);


    std::cout << "Hello " << name;
    std::cout << "Area: " << area << "cm**2";
    std::cout << "Volume: " << volume << "cm**3";

   return 0;
}

double areacalculator(double length){

    double result = length*length;
    return result;
}

double volumecalculator(double length){

    double result = length*length*length;
    return result;
}

std::string fullName(std::string first_Name, std::string last_Name){
    std::string result = first_Name + (' ') + last_Name;
    return result;
}





