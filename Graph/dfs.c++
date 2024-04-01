#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, int source, vector<bool>& visited);

int main() {
    int n = 6; // Number of vertices
    int s = 0; // Source vertex
    vector<vector<int>> graph(n);

    // Adding edges to the graph (undirected)
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);    graph[1].push_back(4);
    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[4].push_back(1);
    graph[4].push_back(2);

    // Create a vector to track visited vertices
    vector<bool> visited(n, false);


    cout << "DFS starting from vertex " << s << ": ";
    dfs(graph, s, visited);

    return 0;
}

void dfs(vector<vector<int>>& graph, int u, vector<bool>& visited) {
    if (visited[u]) return;

    visited[u] = true;
    cout << u << " ";

    for (int v : graph[u]) {
        dfs(graph, v, visited);
    }
}
