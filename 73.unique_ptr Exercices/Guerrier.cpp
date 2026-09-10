#include <iostream>
#include <memory>
#include <string>

struct Epee {
    std::string nom;
    int degats;

    Epee(const std::string& n, int d) : nom(n), degats(d) {
        std::cout << "[+] Epee forgee : " << nom << " (" << degats << " degats)\n";
    }
    ~Epee() {
        std::cout << "[-] Epee brisee / detruite : " << nom << "\n";
    }
    void frapper() const {
        std::cout << "Coup d'epee avec " << nom << " ! -" << degats << " PV\n";
    }
};

class Guerrier {
private:
    std::unique_ptr<Epee> arme;

public:
    void equiper(std::unique_ptr<Epee>& nouvelleArme) {
        arme = std::move(nouvelleArme);
    }

    void attaquer() const {
        if (arme) {
            arme->frapper();
        } else {
            std::cout << "Mains nues ! Pas d'arme equipee.\n";
        }
    }
};

int main() {
    // ------------------------------------------------------------------------
    // A TOI DE JOUER CI-DESSOUS :
    // ------------------------------------------------------------------------

    // ETAPE 1 : Cree une epee avec make_unique.
    // Nom : "Excalibur", degats : 50.
    // Stocke-la dans une variable 'monEpee'.
    // TODO: ...

    std::unique_ptr<Epee> monEpee = std::make_unique<Epee>("Excalibur",50);

    Guerrier arthur;

    arthur.equiper(monEpee);

    // ETAPE 2 : Equipe arthur avec 'monEpee' en utilisant la methode .equiper()
    // Attention a la regle de propriete du unique_ptr !
    // TODO: ...
    

    // ETAPE 3 : Fais attaquer arthur avec sa methode .attaquer()
    // TODO: ...
    arthur.attaquer();


    // ETAPE 4 : Verifie si 'monEpee' possede encore l'epee ou si elle est vide.
    // Ecris une condition if / else :
    // - si monEpee contient encore quelque chose, affiche "Arthur n'a rien pris"
    // - sinon, affiche "monEpee est desormais vide (nullptr)"
    // TODO: ...


    if (monEpee.get()){
        std::cout <<"Arthur n'a rien pris";
    }
    else{
        std::cout <<"monEpee est desormais vide";
    }


    std::cout << "Fin du programme, Arthur quitte la partie...\n";
    return 0;
}