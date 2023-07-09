#include <bits/stdc++.h>
using namespace std;

long nCr(long N, long R)
{
    vector<vector<long>> C(N + 1, vector<long>(R + 1, 0));
    for (long n = 0; n <= N; n++)
    {
        for (long r = 0; r <= min(n, R); r++)
        {
            if (n == 1 || r == 0)
            {
                C[n][r] = 0;
            }
            else
            {
                C[n][r] = C[n - 1][r - 1] + C[n - 1][r];
            }
        }
    }
    return C[N][R];
}