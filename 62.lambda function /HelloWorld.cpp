#include <iostream>
#include <array>
#include <vector>
#include <algorithm>


int main() {

    /*

    auto carre = [](int valeur) {return valeur*valeur;};

    auto exemple = carre(9);
    std::cout << exemple;

    */
    /*
    std::vector<int> values = {3,12,8,25,4,19};

    auto lambda = [](int value){return value>10; };

    int nombre = std::count_if(values.begin(),values.end(),lambda);

    std::cout << nombre;
    */
    /*
    int limite = 10;

    auto lambda = [limite](int x){return x>limite;};

    bool test = lambda(14);

    std::cout << test;

    return 0;
    */


    int compteur = 0;
    auto lambda = [&compteur](int increment){return compteur +=increment;};
    int test = lambda(4);
    std::cout << test;
}

