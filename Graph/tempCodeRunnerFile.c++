
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }