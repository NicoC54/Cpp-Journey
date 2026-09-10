#include <iostream>
#include <memory>

struct Fichier {
    std::string nom;
    Fichier(const std::string& n) : nom(n) { std::cout << "[+] " << nom << " ouvert\n"; }
    ~Fichier() { std::cout << "[-] " << nom << " ferme\n"; }
};

int main() {
    // 1. Creation avec make_shared (compteur = 1)
    auto doc = std::make_shared<Fichier>("rapport.pdf");
    std::cout << "Proprietaires : " << doc.use_count() << "\n"; // 1

    {
        // 2. Copie autorisee : un deuxieme proprietaire arrive (compteur = 2)
        std::shared_ptr<Fichier> copieDoc = doc;
        std::cout << "Proprietaires dans le bloc : " << doc.use_count() << "\n"; // 2
    } 
    // copieDoc meurt ici -> compteur retombe a 1, le fichier RESTE en vie

    std::cout << "Proprietaires apres le bloc : " << doc.use_count() << "\n"; // 1

    return 0;
} // doc meurt ici -> compteur tombe a 0 -> le destructeur ~Fichier() est appele