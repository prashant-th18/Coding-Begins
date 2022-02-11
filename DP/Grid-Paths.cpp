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
    int n; cin >> n;
    vector<vector<char>> v(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    // Bottom-Up Approach
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = n - 1; i >= 0; --i)
    {
        for(int j = n - 1; j >= 0; --j)
        {
            if(i == n - 1 && j == n - 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int op1 = (j == n - 1) ? (0) : (dp[i][j + 1]);
                int op2 = (i == n - 1) ? (0) : (dp[i + 1][j]);
                dp[i][j] = (op1 + op2) % MOD;
            }
            if(v[i][j] == '*') dp[i][j] = 0;
        }
    }
    cout << dp[0][0];
    return 0;
}
// -> Keep It Simple Stupid!
