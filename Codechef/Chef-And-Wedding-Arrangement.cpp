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
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, k; cin >> n >> k;
        vector<vector<ll>> prefix(n, vector<ll>(101, 0));
        vector<ll> dp(n, 0);
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        prefix[0][v[0]] = 1;
        dp[0] = k;
        for (int i = 1; i < n; i++) {
            ll op1 = ((prefix[i - 1][v[i]] == 0) ? (0) : ((prefix[i - 1][v[i]] == 1) ? (2) : (1)));
            ll op2 = k;
            if(op1 < op2)
            {
                dp[i] += dp[i - 1] + op1;
                for(int j = 1; j <= 100; ++j)
                {
                    prefix[i][j] += (prefix[i - 1][j] + (j == v[i]));
                }
            }
            else
            {
                dp[i] += (dp[i - 1] + op2);
                prefix[i][v[i]]++;
            }
        }
        cout << dp[n - 1];
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
