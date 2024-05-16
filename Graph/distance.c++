#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
// shortest distance between source to destination

using namespace std;

int shortestDistanceBFS(vector<vector<int>>& graph, int source, int destination);

int main() {
    int n = 6; // Number of vertices
    int s = 0; // Source vertex
    int d = 4; // Destination vertex
    vector<vector<int>> graph(n);

    // Adding edges to the graph (undirected)
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[4].push_back(1);
    graph[4].push_back(2);

    int shortestDist = shortestDistanceBFS(graph, s, d);

    if (shortestDist == INT_MAX) {
        cout << "There is no path from vertex " << s << " to vertex " << d << "\n";
    } else {
        cout << "Shortest distance from vertex " << s << " to vertex " << d << ": " << shortestDist << "\n";
    }

    return 0;
}

int shortestDistanceBFS(vector<vector<int>>& graph, int source, int destination) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX); // Initialize distances with infinity
    queue<int> q;

    q.push(source);
    distances[source] = 0; // Distance from source to itself is 0

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == destination) {
            return distances[u];
        }

        for (int v : graph[u]) {
            if (distances[v] == INT_MAX) {
                distances[v] = distances[u] + 1; // Update distance
                q.push(v);
            }
        }
    }

    return INT_MAX; // Destination not reachable
}
