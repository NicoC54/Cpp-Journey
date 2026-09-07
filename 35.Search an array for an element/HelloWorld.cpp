#include <iostream>

int indexFinder(int target, int size, int array[]);

int main() {


    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array)/sizeof(array[0]);
    std::cout << "Choisissez le nombre à rechercher";
    int target;
    std::cin >> target;
    int index = indexFinder (target, size, array);


    if (index != -1){
        std::cout << "target is at" << index;
    }

    else{
        std::cout << "target is not present";
    }

    return 0;
}


int indexFinder(int target, int size, int array[]){

    for (int i=0; i<size; i++){
        if(array[i] == target){
            return i;
        }
    }
    return -1;

}

