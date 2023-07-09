#include <bits/stdc++.h>
using namespace std;

//! Edit distance recursion

class Solution
{
private:
    int Distance(int i, int j, string &word1, string &word2)
    {
        // Two base cases
        if (i < 0)
        { // if first string runs out of index that means we need to insert remaining characters in string2
            return j + 1;
        }
        if (j < 0)
        { // if second string runs out of index that means we need to delete the remaining characters of string1 to make it string2.This will add up in the operations
            return i + 1;
        }
        if (word1[i] == word2[j])
        {
            return 0 + Distance(i - 1, j - 1, word1, word2);
        }
        return min((1 + Distance(i - 1, j, word1, word2)), min((1 + Distance(i, j - 1, word1, word2)), (1 + Distance(i - 1, j - 1, word1, word2))));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        return Distance(n - 1, m - 1, word1, word2);
    }
};

//! Edit distance memoisation

class Solution
{
private:
    int Distance(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        // Two base cases
        if (i < 0)
        { // if first string runs out of index that means we need to insert remaining characters in string2
            return j + 1;
        }
        if (j < 0)
        { // if second string runs out of index that means we need to delete the remaining characters of string1 to make it string2.This will add up in the operations
            return i + 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j])
        {
            return 0 + Distance(i - 1, j - 1, word1, word2, dp);
        }
        // First one is delete method as we are deleting in the first string so we want to move the indexes of the first string and move backwards for checking whether that particular index is matching with the index in second string
        // Second one is insert method as we are inserting in first string we want it to stay in its respective index and move the second index
        // Last one is replace method as we want to replace the character with the desired one and also we want to move both the indexes of the strings
        // At last we are returning the minimum value as the question says that we want the minimum number of operations.
        return dp[i][j] = min((1 + Distance(i - 1, j, word1, word2, dp)), min((1 + Distance(i, j - 1, word1, word2, dp)), (1 + Distance(i - 1, j - 1, word1, word2, dp))));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return Distance(n - 1, m - 1, word1, word2, dp);
    }
};

//! Tabulation
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Shifting of indexes and converting it into 1-Based indexing

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            { // as 1 based indexing so shift occurs
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])); // adding 1 as we are either inserting or delting or replacing
            }
        }
    }
    return dp[n][m];
}

//! Space Optimisation

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<int> curr(m + 1, 0), prev(m + 1, 0);

    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
            }
        }
        prev = curr;
    }

    return prev[m];
}