#include <iostream>
#include <cmath>

int main() {
    
    char op;
    double num1;
    double num2;
    double result;

    std::cout <<"***********CALCULATOR************\n";

    std::cout << "insérez votre opération \n";
    std::cin>>op;

    std::cout << "insérez votre premier nombre \n";
    std::cin>>num1;


    std::cout << "insérez votre deuxieme nombre \n";
    std::cin>>num2;


    switch(op){
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;
        default :
            std::cout << "insérez une opération valide \n";

    }

    std::cout << result << std::endl;


    return 0;

}

