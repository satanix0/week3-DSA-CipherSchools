#include <bits/stdc++.h>
using namespace std;

//! Cycle detection in a un-directed graph
bool bfs(int src, vector<int> adj[], int vis[])
{
    queue<pair<int, int>> q;
    vis[src] = 1;
    q.push(make_pair(src, -1));

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(make_pair(it, node));
            }
            else if (it != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool dfs(int src, int parent, vector<int> adj[], int vis[])
{

    vis[src] = 1;

    for (auto it : adj[src])
    {

        if (!vis[it])
        {

            if (dfs(it, src, adj, vis))

                return true;
        }

        else if (it != parent)

            return true;
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    int vis[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {

        if (!vis[i])
        {

            if (bfs(i, adj, vis) == true)

                //   if(dfs(i,-1,adj,vis))

                return "Yes";
        }
    }

    return "No";
}

//! Cycle detection in a directed graph
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node])
    {
        // when the node is not visited
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis) == true)
                return true;
        }

        else if (pathVis[it])
        {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathVis) == true)
                return true;
        }
    }
    return false;
}