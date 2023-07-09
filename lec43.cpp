#include <bits/stdc++.h>
using namespace std;

//! Adjacency Matrix
int main()
{
    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}
//! Adjacency List

void lists()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

//! BFS

vector<int> BFS(int V, vector<int> adj[])
{
    int vis[V] = {0};
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

//! DFS of Graph

void DFS(int node, int vis[], vector<int> adj[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);

    for (auto it : adj[node])
    {
        DFS(it, vis, adj, ls);
    }
}
vector<int> DFS(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;

    DFS(start, vis, adj, ls);
    return ls;
}