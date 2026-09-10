#include <iostream>
#include <memory>
#include <string>

struct Tresor {
    std::string nom;
    int valeur;

    Tresor(const std::string& n, int v) : nom(n), valeur(v) {
        std::cout << "[+] Tresor trouve : " << nom << " (" << valeur << " pieces)\n";
    }
    ~Tresor() {
        std::cout << "[-] Tresor detruit : " << nom << "\n";
    }
};

// 1. Fonction purement observatrice : elle lit la valeur sans posseder l'objet.
// Ne prend PAS de smart pointer en parametre.
void estimerTresor(const Tresor& t) {
    std::cout << "Expertise : " << t.nom << " vaut " << t.valeur << " pieces d'or.\n";
}

class Coffre {
private:
    std::unique_ptr<Tresor> contenu;

public:
    // Depose un tresor dans le coffre (transfert de propriete)
    void stocker(std::unique_ptr<Tresor> t) {
        contenu = std::move(t);
    }

    // Retire le tresor du coffre et le rend a l'appelant.
    // Le coffre doit se retrouver vide.
    std::unique_ptr<Tresor> retirer() {
        return std::move(contenu);
        
    }

    bool estPlein() const {
        return contenu != nullptr;
    }
};

int main() {
    // A. Cree un tresor "Couronne d'or" valant 1000 pieces avec make_unique.
    // Nom de la variable : sacADos
    // TODO

    std::unique_ptr<Tresor> sacADos = std::make_unique<Tresor>("couronne d'or", 1000);


    // B. Utilise la fonction estimerTresor pour afficher sa valeur.
    // Attention : la fonction attend une reference vers l'objet reel, pas le smart pointer !
    // TODO


    estimerTresor(*sacADos); 

    Coffre coffreFort;

    
    coffreFort.stocker(std::move(sacADos));
    // C. Depose le tresor dans le coffreFort.
    // TODO




    // D. Verifie : sacADos doit etre vide, et coffreFort doit etre plein.
    if (!sacADos && coffreFort.estPlein()) {
        std::cout << "Tresor range au coffre en lieu sur !\n";
    }

    // E. Retire le tresor du coffreFort et remets-le dans sacADos.
    // TODO
    sacADos=coffreFort.retirer();


    // F. Verifie : sacADos doit a nouveau contenir le tresor.
    if (sacADos && !coffreFort.estPlein()) {
        std::cout << "Tresor recupere avec succes !\n";
    }

    std::cout << "Fin de l'aventure.\n";
    return 0;
}