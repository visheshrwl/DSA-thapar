#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    int getDegree(int v) {
        return adj[v].size();
    }

    void printAdjacentVertices(int v) {
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    int getNumEdges() {
        int count = 0;
        for (int v = 0; v < V; ++v) {
            count += adj[v].size();
        }
        return count;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Degree of vertex 1: " << g.getDegree(1) << endl;
    cout << "Adjacent vertices of vertex 1: ";
    g.printAdjacentVertices(1);
    cout << "Number of edges: " << g.getNumEdges() << endl;

    return 0;
}
