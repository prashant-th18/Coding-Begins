#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= x; ++j)
        {
            if(j == 0) dp[i][j] = 1;
            else
            {
                int a = (i == 0) ? (0) : (dp[i - 1][j]);
                int b = (j < v[i]) ? (0) : (dp[i][j - v[i]]);
                dp[i][j] = (a + b) % (1000000007);
            }
        }
    }
    cout << dp[n - 1][x];
    return 0;
}
