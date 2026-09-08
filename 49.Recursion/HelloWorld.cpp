#include <iostream>
#include <ctime>

int factorial(int n);
int factorial_recursive(int n);

int main() {

    //factorial(5);
    int sum = factorial_recursive(5);
    std::cout << sum;

    return 0;
}


int factorial(int n){

    int product = 1;

    while(n>=1){
         product *= n;
         n=n-1;
    }

    std::cout << product;
    return product;
   

}

int factorial_recursive(int n){

    if (n <= 1){
        return 1;
    }
        return n*factorial_recursive(n-1);

}