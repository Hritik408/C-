#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, int source, vector<bool>& vis) {

    queue<int> q;

    q.push(source);
    vis[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Using a range-based for loop for iterating through adjacent vertices
        // for (int v : graph[u]) {
        //     if (!vis[v]) {
        //         vis[v] = true;
        //         q.push(v);
        //     }
        // }

          for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!vis[v]) {  // The square brackets [] are used with vectors in C++ to access elements by their index. Since vis is a vector, vis[i] refers to the boolean value at index i.
                vis[v] = true;
                q.push(v);
            }
        }
    }
}


   int connected_comp(vector<vector<int>> graph){
    int n = graph.size();  // represents no of nodes/vertices
    vector<bool> vis(n, false);
    int num_comp = 0;

    for(int i = 0; i < graph.size(); i++){
        if(!vis[i]){
          bfs(graph, i, vis);  // here i as a source node
        //   ++num_comp;
        num_comp++;
        }
    }

    return num_comp;
}

int main() {
    int n = 9;
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
    graph[5].push_back(6);
    graph[7].push_back(8);


    int connected = connected_comp(graph);

    cout<< "No of connected components are : " <<  connected ;

    return 0;
}

