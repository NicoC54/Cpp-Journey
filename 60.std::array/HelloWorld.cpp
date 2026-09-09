#include <iostream>
#include <array>


int main() {

    std::array<int,5> data = {}; //force linitialisation du tableau à 0
    data[0] = 2;
    data[4] = 1;

    for (int integer : data)
    std::cout <<integer<<std::endl;


    return 0;
}

