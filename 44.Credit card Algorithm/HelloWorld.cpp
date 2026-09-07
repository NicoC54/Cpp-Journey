#include <iostream>
#include <string> // Oubli corrigé

int sumOddIndex(const std::string &cardNumber);
int sumPairIndex(const std::string &cardNumber);

int main() {
    std::string carte;
    std::cout << "Entrez un numero de carte : ";
    std::cin >> carte;

    // On appelle les fonctions et on stocke leurs résultats dans le main
    int totalImpair = sumOddIndex(carte);
    int totalPair = sumPairIndex(carte);

    // L'addition finale et la vérification modulo 10
    if ((totalImpair + totalPair) % 10 == 0) {
        std::cout << "Cette carte est VALIDE.\n";
    } else {
        std::cout << "Cette carte est INVALIDE.\n";
    }

    return 0;
}
int sumOddIndex(const std::string &cardNumber){
    int oddSum=0;
    for (int i = cardNumber.size()-1; i>=0; i-=2){
        int number = cardNumber[i] - '0';
        oddSum += number;
    }
    return oddSum;
  }

int sumPairIndex(const std::string &cardNumber){
    int PairSum =0;
     for (int i = cardNumber.size()-2; i>=0; i-=2){
        int number = cardNumber[i] - '0';
        if (number*2 >=10){
            std::string text_number = std::to_string(number*2);
            int number1=text_number[0] - '0';
            int number2=text_number[1] - '0';
            int sum = number1 + number2;
            PairSum += sum;
        }
        else{
        PairSum += number*2;
        }
    }
    return PairSum;
  }

