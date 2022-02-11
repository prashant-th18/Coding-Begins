#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, p, q, r; cin >> n >> p >> q >> r;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll ans = LLONG_MIN;
        vector<array<ll, 3>> dp(n, {ans, ans, ans});
        dp[n - 1][0] = r * v[n - 1];
        dp[n - 1][1] = q * v[n - 1] + dp[n - 1][0];
        dp[n - 1][2] = p * v[n - 1] + dp[n - 1][1];
        for(int i = n - 2; i >= 0; --i)
        {
            dp[i][0] = max(r * v[i], dp[i + 1][0]);
            dp[i][1] = max(q * v[i] + dp[i][0], dp[i + 1][1]);
            dp[i][2] = max(p * v[i] + dp[i][1], dp[i + 1][2]);
        }
        cout << dp[0][2];
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
