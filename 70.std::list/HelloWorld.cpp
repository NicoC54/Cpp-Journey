#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <functional>
#include <map>
#include <unordered_map>
#include <set>



//un set est comme une liste delements uniques

int main() {

std::set<int> setTest = {1,2,3,4,5};

for (int valeur : setTest)
    std::cout <<valeur <<std::endl;

    //insérer un élément au set
    setTest.emplace(10);

for (int valeur : setTest)
    std::cout <<valeur <<std::endl;
    

     //insérer un élément au set en double
      setTest.emplace(10);



for (int valeur : setTest)
    std::cout <<valeur <<std::endl;

    //supprimer un element : 
    setTest.erase(10);

for (int valeur : setTest)
    std::cout <<valeur <<std::endl;

    //afficher le nombre delements uniques
    std::cout <<setTest.size()<<std::endl;

return 0;
}

