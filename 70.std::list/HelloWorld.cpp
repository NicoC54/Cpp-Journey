#include <iostream>
#include <list>


//ATTENTION :: une liste n'a pas d'index, car les éléments ne sont pas stockés les uns a la suite des autres ene mémoire.


int main() {
    std::list<int> chemin = {10, 20, 30};

    // Ajout au tout début (très efficace)
    chemin.push_front(5);

    // Itération (pas de crochets [i])
    for (int point : chemin) {
        std::cout << point << " "; // Affiche : 5 10 20 30
    }

    return 0;
}