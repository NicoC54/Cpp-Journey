#include <iostream>
#include <cmath>

int main() {
    int pin = 0;
    int secret_code = 1234;

    // Trou n°1 : Le mot-clé pour dire au programme "Fais ceci d'abord :"
    do {
        std::cout << "Enter your PIN: ";
        
        // Trou n°2 : La commande pour récupérer la saisie et la stocker dans la variable 'pin'
        std::cin >> pin;
        
    // Trou n°3 : Le mot-clé de fin de boucle
    // Trou n°4 : L'opérateur mathématique pour dire "différent de"
    } while ( pin != secret_code );

    std::cout << "Phone unlocked!\n";
    return 0;
}




