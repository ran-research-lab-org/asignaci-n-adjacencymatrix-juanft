#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Cuenta cuántas aristas existen en el grafo dirigido
    // recorre toda la matriz de adyacencia y suma 1 cada vez que adjMatrix[i][j] == 1
    int numEdges() const {

        int count = 0;

        for(int i = 0; i < numVertices; ++i){
            for(int j = 0; j < numVertices; ++j){
                if(adjMatrix[i][j] == 1)
                    count ++;

            }
        }

        return count;
    }

    // Completa esta funcion
    // Devuelve cuantas aristas llegan al vertice u (su in-degree)
    // Cuenta los 1s en la columna u de la matriz de adyacencia
    // Tira un std::out_of_range si u no esta dentro del rango de vertice
    int inDegree(int u) const {
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        
        int count = 0;
        for(int i = 0; i < numVertices; ++i){
            if(adjMatrix[i][u] == 1)
                count++;
        }
        return count;
    }
       
    

    // Completa esta función
    // Devuelve true si el vertice u tiene el mayor indegree del grafo
    // o si es igual al valor maximo
    // Compara inDegree(u) con todos los vertices
    // Tira un std::out_of_range si u no es valido
    bool isInfluencer(int u) const  {
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");

        int targetDegree = inDegree(u);

        for (int i = 0; i < numVertices; ++i) {
            if (inDegree(i) > targetDegree)
                return false;
        }
        return true;
    }
    

};

