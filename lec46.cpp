//! MST Kruskal's algorithm

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

//! Course Schedule II

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj[numCourses];
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (topo.size() == numCourses)
        return topo;
    return {};
}