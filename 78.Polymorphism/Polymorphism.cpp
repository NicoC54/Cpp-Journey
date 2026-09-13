#include <iostream>
#include <vector>


class Animal{
    public:
        int animal;
        std::string name;

        Animal(int animal, std::string name)
        : animal(animal), name(name){}
        
        virtual ~Animal()=default;



    virtual void AnimalCrie(){
        std::cout << "l'animal crie" << std::endl;
    }
    
};

class Chien : public Animal{

    public:

     void AnimalCrie() override{
        std::cout << "le chien aboie" << std::endl;
    }

    Chien(int animal, std::string name):
    Animal(animal,name){}

};


class Chat : public Animal{

    public :
        std::string breed;

        Chat(int animal, std::string name, std::string breed)
        : Animal(animal,name), breed(breed){}

        void AnimalCrie() override {
        std::cout << "le chat miaule" << std::endl;
    }
    

};

int main(){
    Animal animal(10,"animal");
    Chien chien(20,"toutou");
    Chat chat(10,"miaou","persian");

std::vector<Animal*> animaux{&animal, &chien, &chat};

for (Animal* animal : animaux){
    animal->AnimalCrie();
    
}}