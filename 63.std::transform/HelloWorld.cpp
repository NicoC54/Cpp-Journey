#include <iostream>
#include <array>
#include <vector>
#include <algorithm>


int main() {

    auto lambda = [](int value){return value*value;};

    std::vector <int> test = {1,2,3,4,5};

    std::transform(test.begin(),test.end(),test.begin(), lambda);

    for (int integer : test){
        std::cout << integer <<std::endl;
    }

}

