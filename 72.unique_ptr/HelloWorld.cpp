// ============================================================================
// FICHE MEMO : LES SMART POINTERS EN C++ (C++11 / C++14)
// En-tete obligatoire : #include <memory>
// ============================================================================

#include <iostream>
#include <memory>
#include <string>

struct Ressource {
    std::string nom;
    Ressource(const std::string& n) : nom(n) { std::cout << "[+] " << nom << " allouee\n"; }
    ~Ressource() { std::cout << "[-] " << nom << " detruite\n"; }
    void saluer() const { std::cout << "Ressource " << nom << " active\n"; }
};

// ============================================================================
// 1. std::unique_ptr : Propriete EXCLUSIVE
// ============================================================================
// - Un seul proprietaire a la fois.
// - Ne se copie JAMAIS (constructeur de copie supprime).
// - Se deplace via std::move() (semantique de deplacement).
// - Destruction automatique a la sortie de portee (RAII).
// - Zero surcout memoire par rapport a un pointeur brut (*T).
// ----------------------------------------------------------------------------
void demoUniquePtr() {
    // Creation recommandee (depuis C++14) : std::make_unique
    auto p1 = std::make_unique<Ressource>("A");
    p1->saluer();

    // std::unique_ptr<Ressource> p2 = p1; // ERREUR de compilation : copie interdite !

    // Transfert de propriete explicite :
    std::unique_ptr<Ressource> p2 = std::move(p1);
    // Ici, p1 devient nullptr, p2 possede desormais la ressource "A".

    if (!p1) {
        std::cout << "p1 est desormais vide (nullptr)\n";
    }
} // Sortie de scope : p2 detruit "A" automatiquement.

// ============================================================================
// 2. std::shared_ptr : Propriete PARTAGEE
// ============================================================================
// - Plusieurs pointeurs se partagent la meme ressource.
// - Utilise un compteur de references (Reference Count) atomique alloue sur le tas.
// - La ressource est detruite quand le compteur tombe a 0.
// - Copiable a volonte : chaque copie incremente le compteur.
// ----------------------------------------------------------------------------
void demoSharedPtr() {
    // std::make_shared alloue l'objet et le bloc de controle en une seule passe :
    auto s1 = std::make_shared<Ressource>("B");
    std::cout << "Compteur apres creation : " << s1.use_count() << "\n"; // 1

    {
        auto s2 = s1; // Copie autorisee : incrementation du compteur
        std::cout << "Compteur dans le bloc : " << s1.use_count() << "\n"; // 2
        s2->saluer();
    } // s2 sort du scope : compteur decremente a 1, la ressource n'est pas liberee.

    std::cout << "Compteur apres bloc : " << s1.use_count() << "\n"; // 1
} // s1 sort du scope : compteur tombe a 0, "B" est detruite.

// ============================================================================
// 3. std::weak_ptr : Observateur SANS propriete
// ============================================================================
// - Pointe vers un objet gere par un shared_ptr SANS incrementer son compteur.
// - Sert a resoudre les references circulaires (fuites memoire avec shared_ptr).
// - Ne peut pas acceder directement a l'objet : necessite lock() pour obtenir un shared_ptr.
// ----------------------------------------------------------------------------
void demoWeakPtr() {
    std::weak_ptr<Ressource> observateur;

    {
        auto s = std::make_shared<Ressource>("C");
        observateur = s; // Aucun increment sur s.use_count()

        std::cout << "use_count visible par weak_ptr : " << observateur.use_count() << "\n"; // 1

        // Pour utiliser la ressource, convertir en shared_ptr temporaire :
        if (auto sTemp = observateur.lock()) {
            sTemp->saluer();
        }
    } // Sortie de scope : "C" est detruite car s etait le seul proprietaire.

    // Verification apres destruction de l'objet :
    if (observateur.expired()) {
        std::cout << "La ressource observee n'existe plus !\n";
    }

    if (auto sTemp = observateur.lock()) {
        // Ne sera pas execute
    } else {
        std::cout << "lock() renvoie nullptr car la cible est morte.\n";
    }
}

// ============================================================================
// REGLES D'OR & BONNES PRATIQUES :
// ============================================================================
// 1. Choix par defaut : Toujours std::unique_ptr (conceptuellement le plus propre).
// 2. Partage reel : std::shared_ptr uniquement si la ressource a plusieurs perimetres de vie.
// 3. Allocation : Privilegier make_unique et make_shared plutot que new direct.
// 4. Passage en argument :
//    - const unique_ptr& ou shared_ptr& : Rarement necessaire, lie a la gestion du pointeur.
//    - T* ou T& : A privilegier quand la fonction a juste besoin d'acceder a l'objet sans transferer la propriete.
// ============================================================================

int main() {
    std::cout << "--- TEST UNIQUE_PTR ---\n";
    demoUniquePtr();

    std::cout << "\n--- TEST SHARED_PTR ---\n";
    demoSharedPtr();

    std::cout << "\n--- TEST WEAK_PTR ---\n";
    demoWeakPtr();

    return 0;
}