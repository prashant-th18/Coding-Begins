#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        /*
        vector<array<ll, 2>> dp(n + 1, {0, 0});
        dp[n][0] = dp[n][1] = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
            dp[i][1] = 1;
            if(i != n - 1)
            {
                if(v[i] <= v[i + 1])
                {
                    dp[i][1] += dp[i + 1][1];
                }
            }
        }
        cout << dp[0][0] + dp[0][1] << '\n';
        */
        ll ans = 1;
        vector<ll> dp(n, 0);
        dp[0] = 1; // Base Case
        for(int i = 1; i < n; ++i)
        {
            dp[i] = 1;
            if(v[i] >= v[i - 1])
            {
                dp[i] += dp[i - 1];
            }
            ans += dp[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
