#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>



//std::deque est un conteneur qui permet d'ajotuer ou supprimer des elemetns aux deux extremites, tout en autorisant lacces direct par index
//les données sont stockées sous plusieurs blocs de memoire de taille fixe géré par un tableau de pointeurs
//principales opérations : .push_back .pop_back, push_front, .pop_front en O(1)
//acces direct par index


int main() {

std::deque <int> d = {1,2,3,4,5,6,7};

d.push_back(15);
d.push_front(8);

for (int integer : d){
    std::cout << integer << std::endl;
 
}

    

  

}

