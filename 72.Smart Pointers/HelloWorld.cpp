#include <iostream>
#include <memory>


    //std::unique_ptr ; pointeur intelligent par défaut, indique qu'un seul propriétaire possède la ressource
    // à un isntant donné

    //std::shared_ptr : un pointeur qui permet de partager une ressource

    //std::weak_ptr

    //make_unique : alloue la mémoire et cree l'objet avec un new caché,
    //puis emballe immédiatement à l'adresse de cet objet dans un std::unique_ptr et le renvoie

    //ici un_ptr. j'accède au pointeur, et un_ptr-> j-accède à l'objet
    
    //std::unique_ptr<SmartObject> un_ptr  : on déclare et initialise un pointeur de tyê unique_ptr qui pointe vers un objet de type SmartObject
    //std::make unique va construire cet objet std::make_unique<SmartObject>(); avec les parenthese = l'appel au constructeur



class SmartObject {
    public:
        SmartObject(){
            std::cout << "Constructeur smartobject appelé" <<std::endl;

    }
    void DisplayRandomMsg(){
        std::cout << "Message affiché" << std::endl;
    }
    private:
        int m_a;
};


int main() {


    std::unique_ptr<SmartObject> un_ptr = std::make_unique<SmartObject>();
    un_ptr.



    




    return 0;
    }