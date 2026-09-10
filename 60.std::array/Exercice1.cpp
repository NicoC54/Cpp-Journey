#include <iostream>
#include <array>


/* EXERCICE 1
int main() {

    std::array <float,3> coords = {};
    coords[0] = 1.5;
    coords[1] = 1.5;

    coords.at(2) = 2;

    for (const float& coord : coords)
        std::cout << coord <<std::endl;


    return 0;
}

*/

/* EXERCICE 2
void calculerMoyenne(const std::array <int,5>& array);

int main() {

    std::array <int,5> coords = {12,15,14,11,13};

    for (const float& coord : coords)
        std::cout << coord <<std::endl;

    calculerMoyenne(coords);


    return 0;
}

void calculerMoyenne(const std::array <int,5>& array){
    float somme = 0;
    float moyenne = 0;
    for (int valeur : array)
        somme +=valeur;

    moyenne = somme / array.size();
    std::cout << "average value is " << moyenne;

}*/

//EXERCICE 3

void mettreAJourPosition(std::array<float, 3>& position, const std::array<float, 3>& vitesse);

int main() {

    std::array<float, 3> position = {10.0f, 20.0f, 5.0f};
    std::array<float, 3> vitesse = {1.0f, -0.5f, 0.0f};

    mettreAJourPosition(position, vitesse);


    return 0;
}

void mettreAJourPosition(std::array<float, 3>& position, const std::array<float, 3>& vitesse){

    for (int i=0; i < position.size(); i++){
        position[i] += vitesse[i];
        std::cout << position [i] << std::endl;
    }
}