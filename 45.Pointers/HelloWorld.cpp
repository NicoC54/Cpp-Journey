#include <iostream>

int main() {

    // pointers = variable that stores a memory adress of another variable
    //because sometimes its easier to work with an adress

    // & adress of operator
    //* dereference of operator

    std::string name = "Bro";
    int age = 21;
    std::string* pname = &name;
    int* page = &age;

    std::string freePizzas[5] = {"pizza1","pizza2","pizza3","pizza4","pizza5"};
    


    std::cout << pname << '\n';
    std::cout << *pname << '\n';
    std::cout << *page << '\n';

    std::cout << *freePizzas << '\n';



    return 0;
}


