#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    int s, n; cin >> s >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= s; ++j)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                int op1 = dp[i - 1][j];
                int op2 = ((v[i - 1] <= j) ? (dp[i - 1][j - v[i - 1]] + v[i - 1]) : (0));
                dp[i][j] = max(op1, op2);
            }
        }
    }
    cout << dp[n][s];
    return 0;
}
