#include <iostream>
#include <vector>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& graph, int from, int to) {
    graph[from].push_back(to);
}

// Function to print the graph
void printGraph(const vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Adjacent to vertex " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // Number of vertices in the graph
    int vertices = 4;

    // Create a vector to represent the adjacency list
    vector<vector<int>> graph(vertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    // Print the graph
    printGraph(graph);

    return 0;
}
