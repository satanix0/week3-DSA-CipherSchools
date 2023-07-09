#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LongestSumIncreasingSubsequence(vector<int> &vec)
    {
        vector<int> lis(vec.size());
        int maxLis = INT_MIN;
        for (int i = 0; i < vec.size(); i++)
        {
            lis[i] = vec[i];
            maxLis = max(maxLis, lis[i]);
        }

        for (int i = 1; i < vec.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (vec[j] < vec[i]) // LIS
                {
                    lis[i] = max(lis[i], lis[j] + vec[i]);
                }
            }
            maxLis = max(maxLis, lis[i]);
        }

        return maxLis;
    }
};

int main()
{
    vector<int> vec = {10, 22, 9, 33, 21, 50, 41, 60};
    return 0;
}

//! Palindromic Subsequence

class Solution
{
public:
    int longestPalindrome(string word1, string word2)
    {
        string s = word1 + word2;
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int window, i, j;
        for (i = 0; i < len; i++)
        {
            dp[i][i] = 1;
        }

        for (window = 2; window <= len; window++)
        {
            for (i = 0; i < len - window + 1; i++)
            {
                j = i + window - 1;
                if (window == 2)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
                else
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < word1.size(); i++)
        {
            for (int j = word2.size() - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    result = max(result, dp[i][word1.length() + j]);
                }
            }
        }
        return result;
    }
};