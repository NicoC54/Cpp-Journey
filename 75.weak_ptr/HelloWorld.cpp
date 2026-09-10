#include <iostream>
#include <memory>
#include <string>

struct Joueur {
    std::string pseudo;
    // std::weak_ptr pour eviter le cycle infini !
    std::weak_ptr<Joueur> ami;

    Joueur(const std::string& p) : pseudo(p) {
        std::cout << "[+] Joueur connecte : " << pseudo << "\n";
    }
    ~Joueur() {
        std::cout << "[-] Joueur deconnecte : " << pseudo << "\n";
    }

    void direBonjourAAmi() const {
        // .lock() tente de creer temporairement un shared_ptr
        // Si l'ami a ete detruit, lock() renvoie nullptr
        if (auto spAmi = ami.lock()) {
            std::cout << pseudo << " dit bonjour a " << spAmi->pseudo << " !\n";
        } else {
            std::cout << pseudo << " constate que son ami est hors-ligne.\n";
        }
    }
};

int main() {
    auto alice = std::make_shared<Joueur>("Alice");

    {
        auto bob = std::make_shared<Joueur>("Bob");

        // On lie Alice et Bob
        alice->ami = bob; // ami stocke un weak_ptr vers Bob (ne bloque pas sa destruction)
        bob->ami = alice;

        alice->direBonjourAAmi(); // Bob est en ligne
    } 
    // Fin de vie de bob ici -> compteur de Bob tombe a 0 -> Bob est detruit !

    std::cout << "--- Apres la deconnexion de Bob ---\n";
    alice->direBonjourAAmi(); // Alice tente de parler a Bob, mais lock() echoue proprement

    return 0;
}