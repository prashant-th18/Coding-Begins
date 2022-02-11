#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
vector<vector<ll>> dp;
vector<ll> a, b;
ll range(int i, int j)
{
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j)
    {
        return dp[i][j] = a[i] * b[i];
    }
    return dp[i][j] = a[i] * b[j] + a[j] * b[i] + range(i + 1, j - 1);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n; cin >> n;
        a.assign(n, 0);
        for (ll &val : a) {
            cin >> val;
        }
        b.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        dp = vector<vector<ll>>(n + 1, vector<ll>(n + 1, - 1)); // -1 means not visited
        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i] * b[i];
        }
        ll ans = prefix[n];
        for (int i = 0; i < n; i++) {
            for(int j = i; j < n; ++j)
            {
                ll temp = prefix[i] + prefix[n] - prefix[j + 1];
                temp += range(i, j);
                ans = max(ans, temp);
            }
        }
        cout << ans;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
