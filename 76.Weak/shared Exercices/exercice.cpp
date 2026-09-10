#include <iostream>
#include <memory>
#include <string>

struct Lidar {
    std::string nom;

    Lidar(const std::string& n) : nom(n) {
        std::cout << "[+] LiDAR " << nom << " initialise et actif\n";
    }
    ~Lidar() {
        std::cout << "[-] LiDAR " << nom << " eteint et deconnecte\n";
    }

    void scanner() const {
        std::cout << "LiDAR " << nom << " : balayage a 360 degres effectue.\n";
    }
};

class NodeTraitement {
private:

    std::weak_ptr<Lidar> lidarCible;

public:
    
    void connecterLidar(std::shared_ptr<Lidar> shared_lidar){
         lidarCible = shared_lidar;
    }
    void executerCycle() {
        //if (lidarCible.lock()) fonctionne pas car c'est un weak_ptr, il faut utiliser lock qui renvoie un shared ptr temporaire
        if(auto sp = lidarCible.lock()){
            sp->scanner();         
    }
    else{
        std::cout<<"erreur, capteur non disponible";
    }}
};

int main() {
    NodeTraitement node;

    std::cout << "=== ETAPE 1 : Connexion du capteur ===\n";
    std::shared_ptr<Lidar> monLidar = std::make_shared<Lidar>("rplidar");


    node.connecterLidar(monLidar);
   
    std::cout<<monLidar.use_count() << ": nombre de pointeurs";

    std::cout << "\n=== ETAPE 2 : Premier cycle de traitement ===\n";
   
    node.executerCycle();

    std::cout << "\n=== ETAPE 3 : Deconnexion brutale du capteur ===\n";
  
    monLidar.reset();
    


    std::cout << "\n=== ETAPE 4 : Deuxieme cycle apres deconnexion ===\n";
   
    node.executerCycle();

    std::cout << "\n=== FIN DU PROGRAMME ===\n";
    return 0;
}