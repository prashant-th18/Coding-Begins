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
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int i = 1; i <= x; ++i)
    {
        for(auto val : v)
        {
            if(val <= i)
            {
                dp[i] = (dp[i] + dp[i - val]) % MOD;
            }
        }
    }
    cout << dp[x];
    return 0;
}
// -> Keep It Simple Stupid!
