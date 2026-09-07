#include <iostream>
#include <ctime>


int main() {

    int num;
    int guess;
    int tries=0;

    srand(time(NULL));
    num = (rand()%100) + 1;

    do{
        tries++;
        std::cout << "Donnez un nombre entre 1 et 100 \n";
        std::cin >> guess;

        if (guess > num){
            std::cout << "trop haut! \n";
        }

           if (guess < num){
            std::cout << "trop bas! \n";
        }

    } while (guess!= num);

    std::cout <<"bravo, vous avez mis " << tries << " essais!!!!!" <<std::endl;


   return 0 ;
}


