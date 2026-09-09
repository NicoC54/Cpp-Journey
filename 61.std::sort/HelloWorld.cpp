#include <iostream>
#include <array>
#include <algorithm>


int main() {

std::array <int,9> list = {9,8,7,4,5,6,3,2,1};

std::sort(list.begin(),list.end());

for (int integer : list){
    std::cout << integer << std::endl;
}


    
    return 0;
}

