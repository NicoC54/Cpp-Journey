#include <iostream>

namespace first{
    int x = 1;
}

namespace second {
    int x = 2;
}


int main() {

   using namespace first;
   using std::cout;
   using std::endl;

   cout << x << " has been chosen" << endl;

   std::cout << first::x << " has been chosen in a second time" << std::endl;

   std::cout << second::x << " has been chosen in a third time" << std::endl;

   std::cout << x << " has been chosen in a fourth time" << std::endl;

   return 0;

}