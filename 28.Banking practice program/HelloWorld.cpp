#include <iostream>

int withdraw(int balance, int money);
int deposit(int balance, int money);
void showbalance(int balance);




int main() {
    int balance = 1000;
    int choice;

    do{
    std::cout << "choose 1-4 : 1.show balance, 2.Deposit, 3.withdraw, 4.Exit";
    std::cin >> choice;
    int amount;

   
    switch(choice){

        case 1:
            showbalance(balance);
            break;
        case 2:
            std::cout<< "Enter amount of money";
             std::cin >> amount;
             balance = deposit(balance,amount);
             break;
        case 3:
             std::cout<< "Enter amount of money";
             std::cin >> amount;
             balance = withdraw(balance,amount);
             break;
        case 4:
            std::cout<< "Bye bye";
            break;
        default:
            std::cout <<"Enter a correct number";
    }
    } while (choice!=4);
    

    return 0;
}

int withdraw(int balance, int money){

    balance -= money;
    std::cout << "you just withdraw: " << money << std::endl;
    std::cout << "your new balance is " << balance << std::endl;
    return balance;
}
int deposit(int balance, int money){
    balance += money;
    std::cout << "you just deposit: " << money << std::endl;
    std::cout << "your new balance is " << balance << std::endl;
    return balance;
}

void showbalance(int balance){
    std::cout << "your balance is " << balance << std::endl;
}
