#include <bits/stdc++.h>
using namespace std;

//! LCS
//* Memoisation
int f(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (text1[ind1] == text2[ind2])
    {
        return 1 + f(ind1 - 1, ind2 - 1, text1, text2, dp);
    }
    return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, text1, text2, dp), f(ind1, ind2 - 1, text1, text2, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, text1, text2, dp);
}

//! Tabulation
class Solution
{
private:
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // size has to be changed due to right shift

        for (int i = 0; i < n; i++)
        { // if text2's index becomes 0
            dp[i][0] = 0;
        }
        for (int j = 0; j < m; j++)
        { // if text1's index becomes 0
            dp[0][j] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                {                                                // we cant access negative indexes so shifting of indexes to right occurs
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // since they both match add one and deduce both the strings
                }
                else
                {
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // take the max after reducing either the first index or the second index
                }
            }
        }
        return dp[n][m]; // return this after right shifting of the indexes
    }
};

//! Longest palindromic subsequence
// For this just reverse the given string and perform a lcs on both the strings
class Solution
{
private:
    int lcs(string &s, string &t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};