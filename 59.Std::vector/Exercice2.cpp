#include <iostream>
#include <vector>


void afficherVecteur(const std::vector<int>& vector);
void multiplierParDeux(std::vector<int>& vector);

//---------------------EXO1---------------------------
int main() {

    std::vector<int> integers;
    integers.push_back(10);
    integers.push_back(20);
    integers.push_back(30);
    integers.push_back(40);
    integers.push_back(50);

    std::cout << "Avant multiplication :" << std::endl;
    afficherVecteur(integers);

    multiplierParDeux(integers);

    std::cout << "Apres multiplication :" << std::endl;
    afficherVecteur(integers);

    return 0;
}

//---------------------EXO2---------------------------

void afficherVecteur(const std::vector<int>& vector){
    for (const int& integer : vector)
        std::cout << integer << std::endl;
}

void multiplierParDeux(std::vector<int>& vector){
    for (int& integer : vector)
        integer = 2*integer;
}