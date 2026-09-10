#include <iostream>
#include <vector>
#include <memory>


struct Drone{
    public:
    std::string name;
    int batterie;

    Drone(const std::string name, int batterie){
        this->name = name;
        this->batterie = batterie;
        std::cout << "Drone déployé" <<std::endl;
    }
    ~Drone(){
        std::cout << "Drone détruit" <<std::endl;
    }

    void voler(){
        batterie-= 20;
    }

};


void verifierBatterie(const Drone* d){
    if(d){
        std::cout <<"nom:" << d->name <<std::endl;
        std::cout << "batterie: " << d->batterie << std::endl;
    }
    else{
        std::cout << "aucun drone connecté: " << std::endl;
    }
}

int main(){

    std::vector<std::unique_ptr<Drone>> hangar;
    
    std::unique_ptr<Drone> ptr_drone = std::make_unique<Drone>("Alpha",100);
    hangar.push_back(std::move(ptr_drone));

    verifierBatterie(hangar[0].get());

    std::unique_ptr<Drone> droneEnMission;

    droneEnMission = std::move(hangar[0]);

    droneEnMission->voler();
    droneEnMission->voler();

    droneEnMission.reset(new Drone("Beta",100));

    Drone* droneManuel = droneEnMission.release();

    if (!droneEnMission.get()){
        std::cout<<"Adresse vidée";
    }
    delete droneManuel;









    return 0;
}



