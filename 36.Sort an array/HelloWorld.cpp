#include <iostream>

void sort(int size, int array[]);


int main() {

    int array[] = {10,1,9,2,8,3,7,4,6,5};
    int size = sizeof(array)/sizeof(array[0]);

    sort (size, array);
    for (int number : array){
        std::cout << " " << number;

    }


    return 0;
}

void sort(int size, int array[]){
    for (int i=0; i<size-1; i++){
        for (int j=i; j<size-1-i; j++){
            if (array[j] > array[j+1]){

                int storage = array[j+1];
                array[j+1] = array[j];
                array[j] = storage;
            }
        }
    }
}

