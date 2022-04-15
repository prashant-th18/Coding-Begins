#include<bits/stdc++.h>
using namespace std;
int T, A, B;
vector<vector<bool>> dp(5000001, vector<bool>(2, false)), vis(5000001, vector<bool>(2, false));
bool fun(int t, int ind)
{
    if(t == 0) return true;
    if(ind == 0)
    {
        if(vis[t][0] || vis[t][1]) return dp[t][0] || dp[t][1];
    }
    else
    {
        if(vis[t][1]) return dp[t][1];
    }
    vis[t][ind] = true;
    if(ind == 0)
    {
        if((t >= A / 2) && fun(t - A / 2, 1)) return dp[t][1] = true;
        if((t >= B / 2) && fun(t - B / 2, 1)) return dp[t][1] = true;
        if(fun(t - t / 2, 1)) return dp[t][1] = true;
        if((t >= A) && fun(t - A, 0)) return dp[t][0] = dp[t][1] = true;
        if((t >= B) && fun(t - B, 0)) return dp[t][0] = dp[t][1] = true;
    }
    else
    {
        if((t >= A) && 
    }
        return false;
}
int main()
{
    cin >> T >> A >> B;
    for(int i = T; i >= 0; --i)
    {
        if(fun(i, 0))
        {
            cout << i; return 0;
        }
    }
    return 0;
}

