#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, int source) {
    int n = graph.size();   // 10

    vector<bool> vis(n, false); // Changed to vector<bool> for boolean values
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty()) { // Changed condition from q.size() > 0 to !q.empty()
        int u = q.front();
        q.pop();
        cout << u << " "; // Print the visited node

        for (int neighbor : graph[u]) { // Use range-based for loop for readability
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl; // Add a new line after BFS traversal
}

int main() {
    int no_vertex = 10;
    vector<vector<int>> graph(no_vertex);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[3].push_back(7);
    graph[3].push_back(1);
    graph[4].push_back(7);
    graph[4].push_back(1);
    graph[7].push_back(8);
    graph[7].push_back(4);
    graph[8].push_back(9);  
    graph[8].push_back(7);
    graph[9].push_back(8);

    for (int i = 0; i < no_vertex; i++) {
        if (!graph[i].empty()) {
            cout << "Adjacency list of " << i << " :";
            for (int neighbor : graph[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    int source = 3;
    cout << "BFS traversal starting from node " << source << ": ";
    bfs(graph, source);

    return 0;
}
