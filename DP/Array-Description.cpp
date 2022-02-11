#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
const int MOD = 1e9 + 7;
int32_t main() {
    int n, m; cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(i == 0)
            {
                if(x[i] == 0 || (j == x[i]))
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                if(x[i] == 0 || (j == x[i]))
                {
                    int op1 = dp[i - 1][j - 1];
                    int op2 = dp[i - 1][j];
                    int op3 = (j == m) ? (0) : (dp[i - 1][j + 1]);
                    dp[i][j] = ((op1 + op2) % MOD + op3) % MOD;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    int sum = 0;
    for(int j = 1; j <= m; ++j)
    {
        sum = (sum + dp[n - 1][j]) % MOD;
    }
    cout << sum;
    return 0;
}
// -> Keep It Simple Stupid!
