#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                findTopoSort(it, vis, st, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int N, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (vis[i] == 0)
            {
                findTopoSort(i, vis, st, adj);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

//! Alien Dictionary

class Solution
{
    // works for multiple components
private:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
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
            // node is in your topo sort
            // so please remove it from the indegree

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for (auto it : topo)
        {
            ans = ans + char(it + 'a');
        }
        return ans;
    }
};

//! Dijkstra algorithm

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> distTo(n + 1, INT_MAX); // 1-indexed array for calculating shortest paths
distTo[source] = 0;
pq.push(make_pair(0, source)); // (dist,source)
while (!pq.empty())
{
    int dist = pq.top().first;
    int prev = pq.top().second;
    pq.pop();
    vector<pair<int, int>>::iterator it;
    for (it = g[prev].begin(); it != g[prev].end(); it++)
    {
        int next = it->first;
        int nextDist = it->second;
        if (distTo[next] > distTo[prev] + nextDist)
        {
            distTo[next] = distTo[prev] + nextDist;
            pq.push(make_pair(distTo[next], next));
        }
    }
}

//! Floyd Warshall Algorithm

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j],
                                   matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}