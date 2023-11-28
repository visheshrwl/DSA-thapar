#include <iostream>
#include <queue>

using namespace std;

// Function to perform breadth-first search
void BFS(int** graph, int vertices, int startVertex) {
    // Create an array to keep track of visited vertices
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    queue<int> q;

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                // Mark the adjacent vertex as visited and enqueue it
                visited[i] = true;
                q.push(i);
            }
        }
    }

    delete[] visited;
}

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Create a 2D array to represent the graph
    int** graph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
    }

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "BFS traversal: ";
    BFS(graph, vertices, startVertex);

    // Deallocate memory
    for (int i = 0; i < vertices; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
