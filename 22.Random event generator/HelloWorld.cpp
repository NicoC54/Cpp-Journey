#include <iostream>
#include <ctime>


int main() {



    srand(time(0));

    int randNum = (rand() % 5) +1;

    switch(randNum){
        case 1: std::cout <<"You win a bumper sticker!\n";
            break;
        case 2: std::cout <<"You win a bumper ninja!\n";
            break;
        case 3: std::cout <<"You win a bumper poster!\n";
            break;
        case 4: std::cout <<"You win a bumper golf!\n";
            break;
        case 5: std::cout <<"You win a bumper atom!\n";
            break;
    }

   return 0 ;
}


