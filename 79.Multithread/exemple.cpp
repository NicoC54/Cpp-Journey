#include <iostream>
#include <thread>

void function1() {
    for (int i = 0; i < 500; ++i) {
        std::cout << "+" << std::flush;
    }
}

void function2() {
    for (int i = 0; i < 500; ++i) {
        std::cout << "-" << std::flush;
    }
}

int main() {
    std::thread worker1(function1);
    std::thread worker2(function2);

    worker1.join();
    worker2.join();
    
    std::cout << std::endl;
    return 0;
}