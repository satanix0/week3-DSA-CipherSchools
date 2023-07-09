#include <bits/stdc++.h>
using namespace std;

//! 0/1 Knapsack
//* Memoisation
#include <bits/stdc++.h>

int f(vector<int> &weight, vector<int> &value, int ind, int maxWeight, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        return 0;
    }
    if (dp[ind][maxWeight] != -1)
    {
        return dp[ind][maxWeight];
    }

    int nottake = 0 + f(weight, value, ind - 1, maxWeight, dp);
    int take = INT_MIN;

    if (weight[ind] <= maxWeight)
    {
        take = value[ind] + f(weight, value, ind - 1, maxWeight - weight[ind], dp);
    }
    return dp[ind][maxWeight] = max(nottake, take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(weight, value, n - 1, maxWeight, dp);
}

//! Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int wt = weight[0]; wt <= maxWeight; wt++)
    {
        dp[0][wt] = value[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int nontake = 0 + dp[ind - 1][W];
            int take = INT_MIN;
            if (weight[ind] <= W)
                take = value[ind] + dp[ind - 1][W - weight[ind]];
            dp[ind][W] = max(take, nontake);
        }
    }
    return dp[n - 1][maxWeight];
}