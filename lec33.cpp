#include <bits/stdc++.h>
using namespace std;

//! Subset sum

//* Recursive approach
bool f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
    {
        return true;
    }
    if (ind == 0)
        return arr[0] == target;

    bool nottake = f(ind - 1, target, arr);
    bool take = false;

    if (arr[ind] <= target)
    {
        take = f(ind - 1, target - arr[ind], arr);
    }

    return take | nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return f(n - 1, k, arr);
}

//! Memoization

#include <bits/stdc++.h>

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }

    bool nottake = f(ind - 1, target, arr, dp);
    bool take = false;

    if (arr[ind] <= target)
    {
        take = f(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = take | nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

//! Tabulation

bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nontake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
            {
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take | nontake;
        }
    }

    return dp[n - 1][k];
}

//! Space Optimisation

bool subsetSumToK(int n, int k, vector<int> &arr)
{

    // vector<vector<bool>>dp(n,vector<bool>(k+1, false));
    vector<bool> curr(k + 1, false), prev(k + 1, false);

    for (int i = 0; i < n; i++)
    {
        prev[0] = true;
    }
    prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nontake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
            {
                take = prev[target - arr[ind]];
            }
            curr[target] = take | nontake;
        }
        prev = curr;
    }

    return prev[k];
}

//! Longest Increasing Subsequece
//* Memoisation
int f(int ind, int prev_ind, vector<int> &nums, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    int len = 0 + f(ind + 1, prev_ind, nums, n, dp);
    if (prev_ind == -1 || nums[prev_ind] < nums[ind])
    {
        len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
    }
    return dp[ind][prev_ind + 1] = len;
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, nums, n, dp);
}

//! Tabulation
int f(int ind, int prev_ind, vector<int> &nums, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    int len = 0 + f(ind + 1, prev_ind, nums, n, dp);
    if (prev_ind == -1 || nums[prev_ind] < nums[ind])
    {
        len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
    }
    return dp[ind][prev_ind + 1] = len;
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int len = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            len = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 || nums[prev_ind] < nums[ind])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev_ind + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}