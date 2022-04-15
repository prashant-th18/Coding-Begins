#include<bits/stdc++.h>
using namespace std;
int knapsack(int W, const vector<int>& val, const vector<int>& weight)
{
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= W; ++j)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                int max1 = dp[i - 1][j];
                int max2 = ((j < weight[i - 1]) ? (0) : (dp[i - 1][j - weight[i - 1]])) + val[i - 1];
                dp[i][j] = max(max1, max2);
            }
        }
    }
    return dp[n][W];
}
int knapsack2(int W, const vector<int>& val, const vector<int>& weight)
{
    int n = val.size();
    // observation
    // You only need just the previous dp value to calculate the present value
    vector<vector<int>> dp(2, vector<int>(W + 1, 0));
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= W; ++j)
        {
            if(i == 0 || j == 0)
            {
                dp[i % 2][j] = 0;
            }
            else
            {
                int max1 = dp[(i - 1) % 2][j];
                int max2 = ((j < weight[i - 1]) ? (0) : (dp[(i - 1) % 2][j - weight[i - 1]])) + val[i - 1];
                dp[i % 2][j] = max(max1, max2);
            }
        }
    }
    return dp[n % 2][W];
}
int main()
{
    int n; cin >> n;
    int W; cin >> W;
    vector<int> val(n), weight(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cout << knapsack2(W, val, weight);
    return 0;
}
