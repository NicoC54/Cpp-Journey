#include <iostream>


int main() {

    int rows;
    int lines;

    std::cout <<"nb colonnes";
    std::cin >> rows;

    std::cout <<"nb lignes";
    std::cin >> lines;

    for (int i = 0 ; i< lines; i++){
        
        for (int j = 0 ; j< rows; j++){
        std::cout << "*";       
}
std::cout << '\n';
   }

   return 0;
}


