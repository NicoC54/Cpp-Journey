#include <iostream>

int main() {

std::string foods[5] ;
std::string food;
int size = sizeof(foods)/sizeof(foods[0]);
std::string temp;

for (int i = 0; i < size ; i++){
    std::cout << "Entre 5 nourritures que vous aimez ou arrêtez vous en tapant sur 'q' votre nourriture préférée #" << i+1 ;
    std::getline(std::cin,temp);

    if (temp == "q"){
        break;
    }
    else{
        foods[i] = temp;
}

    
}

for (int i = 0 ; !foods[i].empty(); i++){
std::cout << foods[i] << '\n';
}
   
return 0;
}


