#include <iostream>
#include <vector>




struct Vertex {
    int x;
    int y;
    int z;
};


std::ostream& operator<<(std::ostream& stream, const Vertex& vertex){
    stream << vertex.x << vertex.y << vertex.z;
    return stream;
}



//---------------------EXO1---------------------------
int main() {
    
    std::vector<Vertex> vertices;

    vertices.push_back({1,2,3});
    vertices.push_back({4,5,6});
    vertices.push_back({7,8,9});

    for (const Vertex& vertex : vertices){
        std::cout << vertex << std::endl;
    }

    vertices.erase(vertices.begin()+1);

    for (const Vertex& vertex : vertices){
        std::cout << vertex << std::endl;
    }
    vertices.clear();

    for (const Vertex& vertex : vertices){
        std::cout << vertex << std::endl;
    }

    return 0;
}

//---------------------EXO2---------------------------

