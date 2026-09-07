#include <iostream>
#include <ctime>

int adversaryChoice(int random);
void printAdversaryChoice(int adversary_choice);


int main() {

    srand(time(NULL));
    int random = rand() % 3 + 1;

    std::cout << "----------------------PIERRE PAPIER SCISEAUX----------------------" << std::endl;

    int choice;

    do{
        std::cout << "Bienvenue dans le jeu, choisissez votre action" << std::endl;
        std::cout << "1.Pierre" << std::endl;
        std::cout << "2.Papier" << std::endl;
        std::cout << "3.Sciseaux" << std::endl;
        std::cout << "4.Quitter le jeu" << std::endl;

       
        std::cin >> choice;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erreur : Veuillez entrer un chiffre !\n";
            continue; // Recommence la boucle
        }

        int adversary_choice = adversaryChoice(random);

        if (choice>=1 && choice <=3) {
            printAdversaryChoice(adversary_choice);
        }



        switch (choice){
            case 1:
                switch(adversary_choice){
                    case 1:
                        std::cout << "Vous avez fait Egalité" <<std::endl;
                        break;

                    case 2:
                        std::cout << "Vous avez Perdu" <<std::endl;
                        break;

                    case 3:
                        std::cout << "Vous avez Gagné" <<std::endl;
                        break;

                }
                break;
                
                

            case 2:
                switch(adversary_choice){
                     case 1:
                        std::cout << "Vous avez Gagné" <<std::endl;
                        break;

                    case 2:
                        std::cout << "Vous avez fait Egalité" <<std::endl;
                        break;

                    case 3:
                        std::cout << "Vous avez Perdu" <<std::endl;
                        break;

               

                }
                 break;
                    
             


            case 3:
                switch(adversary_choice){
                    case 1:
                        std::cout << "Vous avez Perdu" <<std::endl;
                        break;

                    case 2:
                        std::cout << "Vous avez Gagné" <<std::endl;
                        break;

                    case 3:
                        std::cout << "Vous avez fait Egalité" <<std::endl;
                        break;

                }

                break;

            case 4:
                 std::cout << "Merci d'avoir joué, à bientôt" << std::endl;
                    break;

            default:
                std::cout << "Veuillez insérer un nombre entre 1 et 4" << std::endl;
                    break;                    
                }

                

        }while(choice!=4);

        return 0;
    

}
    
int adversaryChoice(int random){
    switch(random){
        case 1:  //pierre
            return 1;

        case 2:  //papier
            return 2;

        case 3:  //sciseaux
            return 3;

        default:
            return 1;
    }
}

void printAdversaryChoice(int adversary_choice){
    if (adversary_choice==1){
        std::cout << "L'ordinateur a choisi Pierre, ";
    }
    else if (adversary_choice==2){
        std::cout << "L'ordinateur a choisi Papier, ";
    }
    else {
        std::cout << "L'ordinateur a choisi Scisceaux, ";
    }
}


