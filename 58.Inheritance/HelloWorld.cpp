#include <iostream>

/*class Animal{
    public:
        bool alive = true;

        void eat(){
        std::cout <<"This animal is eating\n";
    }
};

class Dog : public Animal{
    public:
        void bark(){
            std::cout << "The dog goes woof!\n";
        }

};

class Cat : public Animal{
    public:
        void meow(){
            std::cout << "The cat goes meow!\n";

        }
};

*/

class Shape{
    public:
        double area;
        double volume;
};

class Cube : public Shape{
    public:
        double side;
    
    Cube(double side){
        this->side = side;
        this->area = side*side*6;
        this->volume = side*side*side;
    }
    


};

class Sphere : public Shape{
    public:
        double radius;
    Sphere(double radius){
        this->radius = radius;
        this->area = 4*3.14*(radius*radius);
        this->volume = (4/3.0) * 3.14 * (radius*radius*radius);
    }

    };




int main() {

    Sphere sphere(4);
    std::cout<<sphere.radius<<std::endl;
    std::cout<<sphere.volume<<std::endl;
    std::cout<<sphere.area<<std::endl;

    Cube cube(10);

    std::cout<<cube.area<<std::endl;
    std::cout<<cube.volume<<std::endl;


    return 0;
}

