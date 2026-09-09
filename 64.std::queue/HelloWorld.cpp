#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>

//ATTENTION IMPOSSIBLE DINITIALISER UNE QUEUE = {1,5,6,7,3} ..... on doit passer une deque 

//std::vector<int> donnees = {10, 2, 6, 5, 7};

// On transforme le vector en deque à la volée pour l'injecter dans la queue

// std::queue<int> maFile(std::deque<int>(donnees.begin(), donnees.end()));


// std::queue gere les données selon une FIFO : first in first out. on ajoute un element avec un .push() 
// et on lit le plus ancien avec .front() et retire avec .pop()
// cas d'usage en robotique : creer une fenêtre glissante pour lisser les lectures d'un capteur = conserver les 20 dernieres et supprimer la plus ancienne


int main() {

    std::queue <int> file;

    file.push(4);
    std::cout<<file.front()<<std::endl;
    file.push(7);
    std::cout<<file.front()<<std::endl;
    file.pop();
    std::cout<<file.front()<<std::endl;

    

    std::vector<int> donnees = {1, 2, 6, 5, 7};

    std::queue<int> queue_initialisee(std::deque<int>(donnees.begin(),donnees.end()));
    std::cout<<queue_initialisee.front()<<std::endl;

}

