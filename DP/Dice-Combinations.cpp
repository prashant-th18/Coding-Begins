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
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= 6; ++j)
        {
            if(j > i) break;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}
// -> Keep It Simple Stupid!
