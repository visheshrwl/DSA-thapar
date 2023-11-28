#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjacencyMatrix[src][dest] = 1;
        }
    }

    int getDegree(int vertex) {
        int degree = 0;
        if (vertex >= 0 && vertex < numVertices) {
            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[vertex][i] == 1) {
                    degree++;
                }
            }
        }
        return degree;
    }

    std::vector<int> getAdjacentVertices(int vertex) {
        std::vector<int> adjacentVertices;
        if (vertex >= 0 && vertex < numVertices) {
            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[vertex][i] == 1) {
                    adjacentVertices.push_back(i);
                }
            }
        }
        return adjacentVertices;
    }

    int getNumEdges() {
        int numEdges = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    numEdges++;
                }
            }
        }
        return numEdges;
    }
};

int main() {
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    std::cout << "Degree of vertex 2: " << graph.getDegree(2) << std::endl;

    std::cout << "Adjacent vertices of vertex 2: ";
    std::vector<int> adjacentVertices = graph.getAdjacentVertices(2);
    for (int vertex : adjacentVertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of edges: " << graph.getNumEdges() << std::endl;

    return 0;
}
