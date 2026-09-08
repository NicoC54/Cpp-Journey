#include <iostream>

int main() {

  //null value = a special value that means something has no value.

  //when a pointer is holding a null value,
  //that pointer is not pointing to anything (null pointer)

  //nullptr = keyword represents a null pointer litteral

  //nullptrs are helpful when determining if an adress
  //was successfully assigned to a pointer

    int* pointer = nullptr;
    int x = 123;
    pointer = &x;

    if(pointer == nullptr){
        std::cout << "address was not assigned! \n";
    }
    else{
        std::cout << "address was assigned! \n";
        std::cout << *pointer;
    }


    return 0;
}


