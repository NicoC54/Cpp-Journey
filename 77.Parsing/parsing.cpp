#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void lireFichier(const std::string& chemin){
    std::ifstream fichier(chemin);


    if(!fichier.is_open()){
        std::cerr << "Erreur: impossible d'ouvrir le fichier" << chemin << '\n';
        return;
    }

    std::string ligne; //définition dune ligne

    while(std::getline(fichier, ligne)){ //tant que le fichier contient des lignes
        std::stringstream ss(ligne); //conversion d'une ligne en stringstream, morceaux coupables
        std::string token; //buffer
        if (ligne.empty() || ligne[0]=='#'){ //skip si ligne vide ou premiere valeur = # debut de def
            continue; 
        }
        std::getline(ss,token, ','); //recupérer la partie de string jusquau point virgule
        int id = std::stoi(token); //convertir cette partie en int
        std::getline(ss,token, ',');
        double lat = std::stod(token);
        }

   


}