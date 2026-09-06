#include <iostream>
#include <cmath>

//std::getline(std::cin,name) sert a prendre les caracteres en espaces aussi

//name.insert(index, what to insert) ex : baba.insert(0,"@") = @baba

//name.append("what to chain as the first string name") ex : baba.append("allo") = babaallo

//name.at(0) = afficher le caractere dindexe 0

//name.clear() = remove name

//name.find(' ') : give the index of the first character inside, here is a space

//name.erase(start_index, ending_index);



 

int main() {
    
    std::string name;

    std::cout << " Enter your name";
    std::getline(std::cin,name);

    name.erase(0,2);

    std::cout << name;

    return 0;


}

