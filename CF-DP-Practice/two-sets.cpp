#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    int s = n * (n + 1);
    if(s % 4 != 0) cout << 0;
    else
    {
        s /= 4;
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= s; ++j)
            {
                if(j == 0) dp[i][j] = 1;
                else
                {
                    int op1 = dp[i - 1][j];
                    int op2 = ((j < i) ? (0) : (dp[i - 1][j - i]));
                    dp[i][j] = (op1 + op2) % (1000000007);
                }
            }
        }
        cout << dp[n][s];
    }
    return 0;
}
