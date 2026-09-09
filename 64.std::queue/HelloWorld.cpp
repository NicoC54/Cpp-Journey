#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>



// std::queue gere les données selon une FIFO : first in first out. on ajoute un element avec un .push() 
// et on lit le plus ancien avec .front() et retire avec .pop()
// cas d'usage en robotique : creer une fenêtre glissante pour lisser les lectures d'un capteur = conserver les 20 dernieres et supprimer la plus ancienne


int main() {

    std::queue <int> file;

    file.push(4);
    std::cout<<file.front();
    file.push(7);
    std::cout<<file.front();
    file.pop();
    std::cout<<file.front();

    

  

}

