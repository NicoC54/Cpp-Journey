#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <functional>

//ATTENTION IMPOSSIBLE DINITIALISER UNE PRIORITY_QUEUE = {1,5,6,7,3} ..... on doit passer un vector

//std::vector<int> donnees = {10,2,3,4,5,6};
//std::priority_queue<int> exemple_base(donnees.begin(), donnees.end());

//std::priority queue (type de données, vecteur du type de données, regle de priorité)
// exemple : std::priority_queue<int> = version par defaut
// exemple complet : std::priority_queue<int, std::vector<int>, std::greater<int> maFile;


int main() {

std::priority_queue<int> exemple_base;
exemple_base.push(99);
exemple_base.push(15);
exemple_base.push(7);
exemple_base.push(5);
exemple_base.push(6);

int value = exemple_base.top();
std::cout <<value <<std::endl;
    

std::priority_queue<int, std::vector<int>, std::greater<int>> exemple_pousse; 
exemple_pousse.push(99);
exemple_pousse.push(15);
exemple_pousse.push(7);
exemple_pousse.push(5);
exemple_pousse.push(6);

int test = exemple_pousse.top();
std::cout <<test <<std::endl;



//EXEMPLE INITIALISATION PRIORITY QUEUE

std::vector<int> donnees = {1,2,3,4,5,6};
std::priority_queue<int> exemple_vecteur(donnees.begin(), donnees.end());
int sortie = exemple_vecteur.top();

std::cout <<"la sortie est "<< sortie <<std::endl;

}

