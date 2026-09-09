#include <iostream>
#include <vector>



//---------------------EXO1---------------------------
int main() {

    std::vector<int> integers;
    integers.push_back(10);
    integers.push_back(20);
    integers.push_back(30);
    integers.push_back(40);
    integers.push_back(50);
/*
    for (int i = 0; i< integers.size(); +i++) // premiere boucle
        std::cout << integers[i] <<std::endl;
        */

    for (int integer : integers)
        std::cout << integer << std::endl;

    return 0;
}
