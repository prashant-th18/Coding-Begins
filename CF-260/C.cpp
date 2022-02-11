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
        // dp[i] => Maximum points I can get optimally from [0 .. i]
        int n; cin >> n;
        vector<ll> cnt(2e5, 0);
        for (int i = 0; i < n; i++) {
            int tt; cin >> tt;
            cnt[tt]++;
        }
        vector<ll> dp(2e5, 0);
        for (int i = 0; i < 2e5; i++) {
            ll one = cnt[i] * i + ((i >= 2) ? (dp[i - 2]) : (0));
            ll two = (i >= 1) ? (dp[i - 1]) : (0);
            dp[i] = max(one, two);
        }
        cout << dp[(int)2e5 - 1];
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
