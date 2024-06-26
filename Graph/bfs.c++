#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, int source)
{
    int n = graph.size();
    vector<bool> vis(n, false);
    queue<int> q;

    q.push(source);
    vis[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();

        // Using a range-based for loop for iterating through adjacent vertices
        // for (int v : graph[u]) {
        //     if (!vis[v]) {
        //         vis[v] = true;
        //         q.push(v);
        //     }
        // }

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main()
{
    int n = 6; // Number of vertices
    int s = 0; // Source vertex
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

    cout << "BFS starting from vertex " << s << ": ";
    bfs(graph, s);

    return 0;
}
