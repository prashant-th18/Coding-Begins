#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(sz(a) + 1, vector<int>(sz(b) + 1, 0));
    for(int i = sz(a); i >= 0; --i)
    {
        for(int j = sz(b); j >= 0; --j)
        {
            if(i == sz(a) || j == sz(b))
            {
                dp[i][j] = max(sz(a) - i, sz(b) - j);
            }
            else
            {
                int mini = 1e9;
                (a[i] == b[j]) ? (mini = dp[i + 1][j + 1]) : (0);
                int op1 = 1 + dp[i + 1][j + 1]; // Replace
                int op2 = 1 + dp[i + 1][j]; // Delete
                int op3 = 1 + dp[i][j + 1]; // Insert
                dp[i][j] = min({mini, op1, op2, op3});
            }
        }
    }
    cout << dp[0][0];
    return 0;
}
// -> Keep It Simple Stupid!
