#include <iostream>


void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);


int main() {

    bakePizza();
    bakePizza(": fromage!");
    bakePizza("fromage", " and peperoni");


   return 0;
}


void bakePizza(){
    std::cout << "Here is your pizza!\n";
    }


void bakePizza(std::string topping1){
    std::cout << "Here is your topping!" << topping1 << '\n';
    }

    void bakePizza(std::string topping1, std::string topping2){
    std::cout << "Here is your topping!" << topping1 << topping2 << '\n';
    }




