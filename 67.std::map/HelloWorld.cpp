#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <functional>
#include <map>


//MAP EST UN DICTIONNAIRE ORDONNE, en gros ca va trier les valeurs selon un ordre chronologique

int main() {


std::map<double, std::string> historiqueTrajectoire;

    historiqueTrajectoire[0.0] = "Demarrage";
    historiqueTrajectoire[2.5] = "Contournement obstacle";
    historiqueTrajectoire[1.1] = "Acceleration"; // Automatiquement trié entre 0.0 et 2.5


    for (const auto& paire : historiqueTrajectoire){
        std::cout << paire.first << "s : " << paire.second << std::endl;
    }
  
    //ou DEUXIEME NOTATION


    for (const auto& [cle,valeur] : historiqueTrajectoire){
        std::cout << cle << "s : " << valeur << std::endl;
    }

    //ajouter un couple clé/valeur:
    historiqueTrajectoire[7]="test_ajout";

    //tester si la clé existe avec.at(clé) : renvoie la valeur de la clé, si la clé nexiste pas renvoie une exception
    std::string test = historiqueTrajectoire.at(7);
    std::cout << test <<std::endl;

    historiqueTrajectoire.emplace(15, "faisons un test");
    
     for (const auto& [cle,valeur] : historiqueTrajectoire){
        std::cout << cle << "s : " << valeur << std::endl;
    }

    //tester si la clé est présente ou pas : renvoie 1 si oui 0 sinon

    bool check = historiqueTrajectoire.count(15);
    bool check2 = historiqueTrajectoire.count(90);

    std::cout <<check<< std::endl;; //renvoie 1
    std::cout <<check2<< std::endl;; //renvoie 0

    //erase supprime une clé:

    historiqueTrajectoire.erase(15);
    check = historiqueTrajectoire.count(15);
    std::cout <<"verif apres erase" << check<< std::endl;; //renvoie 1

    //clear le dico : .clear()

    //.size() renvoie le nombre de paires clé/valeur et .empty() renvoie true ou false si le dico est vide ou pas



return 0;
}

