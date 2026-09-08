#include <iostream>
#include <ctime>

int main() {

    /*
    int* pNum = NULL;

    pNum = new int;

    *pNum = 21;

    std::cout <<"adress: " <<pNum << '\n';
    std::cout <<"adress: " <<*pNum << '\n';

    delete pNum;
    */

    char* pGrades = NULL;

    int size;

    std::cout << "how many grades";
    std::cin >> size;

    pGrades = new char[size];

    for(int i=0; i<size; i++){
        std::cout << "Enter grade #" <<i+1 << " : ";
        std::cin >> pGrades[i];
    }

    for (int i=0; i < size;i++){
        std::cout<<pGrades[i] <<'\n';

    }

    delete[] pGrades; //on ajoute des crochets si on supprime un tableau

    return 0;

    
}

