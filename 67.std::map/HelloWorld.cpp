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


return 0;
}

