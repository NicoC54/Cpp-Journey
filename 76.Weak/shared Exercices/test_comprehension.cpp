#include <memory>
#include <iostream>



int main(){

    std::shared_ptr<int> shr_ptr = std::make_shared<int>(10);
    std::weak_ptr<int> weak_ptr;

    weak_ptr = shr_ptr;

    std::cout<<shr_ptr.use_count()<<std::endl;

    std::shared_ptr<int> shr_ptr2 = shr_ptr;

    std::cout<<"compteur avant le lock: " << shr_ptr.use_count()<<std::endl;


    if (auto sp = weak_ptr.lock()){
        std::cout<<"valeur lue par le weak ptdr" << sp << *sp <<std::endl;
        std::cout<<"compteur apres le lock: " << shr_ptr.use_count()<<std::endl;
    }

    shr_ptr2.reset();
    std::cout << "Compteur après reset de shr_ptr2 : " << shr_ptr.use_count() << std::endl; 

    std::cout << "weak_ptr est-il expiré ? " << (weak_ptr.expired() ? "Oui" : "Non") << std::endl; // Affiche Non


    shr_ptr.reset();

    std::cout << "weak_ptr après reset total : " << (weak_ptr.expired() ? "Expiré !" : "Vivant") << std::endl;

     if (auto sp = weak_ptr.lock()){
        std::cout<<"valeur lue par le weak ptdr" << sp << *sp <<std::endl;
        std::cout<<"compteur apres le lock: " << shr_ptr.use_count()<<std::endl;
    }






}