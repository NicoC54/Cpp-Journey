#include <iostream>
#include <fstream>
#include <string>

void lireFichier(const std::string& chemin){
    std::ifstream fichier(chemin);

    if(!fichier.is_open()){
        std:cerr << "Erreur: impossible d'ouvrir le fichier" << chemin << '\n';
        return;
    }
    std::string ligne;

    while(std::getline(fichier, ligne)){
        if ligne.empty() || ligne[0]=='#'){
            continue;
        }
    }
}