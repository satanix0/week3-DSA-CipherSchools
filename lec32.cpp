#include<bits/stdc++.h>
using namespace std;

//! Minimum coins 
//* Recursive Approach
#include <bits/stdc++.h> 

int f(vector<int>&num, int T, int ind){
    if(ind == 0){
        if(T % num[0] == 0){
            return T / num[0];
        } 
        else{
            return 1e9;
        }
    }

    int nontake =0 + f(num, T, ind-1);
    
    int take = INT_MAX;
    if(num[ind] <= T){
        take = 1+ f(num , T-num[ind], ind);
    }
    return min(take, nontake);
}


int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    int ans = f(num , x, n-1);
    
    if(ans >= 1e9){
        return -1;
    }
    else {
        return ans;
    }   
}

//! Applying memoization

#include <bits/stdc++.h> 

int f(vector<int>&num, int T, int ind, vector<vector<int>>&dp){
    if(ind == 0){
        if(T % num[0] == 0){
            return T / num[0];
        } 
        else{
            return 1e9;
        }
    }
    
    if(dp[ind][T] != -1){
        return dp[ind][T];
    }

    int nontake =0 + f(num, T, ind-1, dp);
    
    int take = INT_MAX;
    if(num[ind] <= T){
        take = 1+ f(num , T-num[ind], ind,dp);
    }
    return dp[ind][T] = min(take, nontake);
}


int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    
    vector<vector<int>>dp(n, vector<int>(x+1, -1));
    int ans = f(num , x, n-1,dp);
    
    if(ans >= 1e9){
        return -1;
    }
    else {
        return ans;
    }
    
}

//! Tabulation 
int minimumElements(vector<int> &arr, int T)
{
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}

//! Space Optimisation

int minimumElements(vector<int> &arr, int T)
{
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    vector<int>prev(T+1, 0), curr(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + curr[target - arr[ind]];
                
            curr[target] = min(notTake, take);
        }
        prev = curr;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}