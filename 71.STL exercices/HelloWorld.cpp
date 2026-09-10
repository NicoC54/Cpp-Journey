#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <deque>
#include <list>


//ATTENTION :: une liste n'a pas d'index, car les éléments ne sont pas stockés les uns a la suite des autres ene mémoire.
void printVector(const std::vector<int>& vector);
void printSet(const std::set<int>& set);

int main() {


    //QUESTION 1
    int tableau[9]= {1,100,2,8,3,9,4,5,15};
    int length = sizeof(tableau)/sizeof(tableau[0]);
    std::vector<int> tableau_dynamique;

    for (int i=0;i<length;i++){
        tableau_dynamique.push_back(tableau[i]);
    }

    printVector(tableau_dynamique);

    auto lambda = [](int value){return value*value;};
    std::transform(tableau_dynamique.begin(),tableau_dynamique.end(),tableau_dynamique.begin(), lambda);
    printVector(tableau_dynamique);
    std::sort(tableau_dynamique.begin(),tableau_dynamique.end());
    printVector(tableau_dynamique);

    //QUESTION 2

    int piecesTraversees[8] = {101, 103, 102, 101, 104, 103, 105, 102};
    std::set<int> RobotParts;

    for (int element : piecesTraversees)
        RobotParts.emplace(element);

    printSet(RobotParts);

    
    //QUESTION 3 annuaire

    std::unordered_map<int,std::string> annuaire;
    annuaire[10] ="Moteur Gauche"; 
    annuaire[20] ="Moteur Droit"; 
    annuaire[30] ="LiDAR Principal"; 
    annuaire[40] ="Caméra RGB"; 

    std::string sortie = annuaire.at(10);
    std::cout << sortie <<std::endl;

    for (const auto& paire : annuaire){
        std::cout << "Identifiant: " << paire.first << " Nom: " << paire.second <<std::endl;
    }

    //QUESTION 4 JOURNAL

    
    std::map<float,std::string> journal;

    journal[0.12] = "Démarrage du système";
    journal[1.45] = "Connexion LiDAR établie";
    journal[3.80] = "Alerte obstacle proche";

      for (const auto& paire : journal){
        std::cout << "Valeur: " << paire.first << " Nom: " << paire.second <<std::endl;
    }

    //QUESTION 5

    int waypointsInitiaux[5] = {15, 80, 40, 95, 30};

    std::list<int> liste(waypointsInitiaux, waypointsInitiaux+5);
    auto it = liste.begin();
    std::advance(it,2);
    liste.insert(it, 30);


    //QUESTION 6

    std::priority_queue <int> urgences;

    for (int element : waypointsInitiaux)
        urgences.push(element);

    std::cout << urgences.top();

    //QUESTION 7

    std::deque <std::string> tampon_bidirectionnel = {"CMD_MOVE_FORWARD","CMD_STOP","SENSOR_REQUEST"};

    //pour ajouter a lavant ou larriere : push_front() push_back, pour supprimer pop_front() pop_back()

    return 0;
}

void printVector(const std::vector<int>& vector){
    for (int element : vector)
        std::cout <<element<<std::endl;
}

void printSet(const std::set<int>& set){
       for (int element : set)
        std::cout <<element<<std::endl;
}

