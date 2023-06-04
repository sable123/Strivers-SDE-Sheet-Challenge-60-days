#include<limits.h>

int maxProfit(vector<int> &values, vector<int> &weights, int n, int W)
{

    vector<vector<int>> dp(n,vector<int>(W+1,0));


    for(int i=weights[0]; i<=W; i++){
        dp[0][i] = values[0];
    }

    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){

            int notTaken = 0 + dp[ind-1][cap];

            int taken = INT_MIN;
            if(weights[ind] <= cap)
                taken = values[ind] + dp[ind-1][cap - weights[ind]];

            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n-1][W];
}
