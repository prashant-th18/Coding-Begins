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
        string v; cin >> v;
        int n = sz(v);
        if(n == 1)
        {
            cout << 0 << '\n'; continue;
        }
        vector<int> dp(n - 1, 0);
        dp[0] = (v[0] != v[1]);
        for(int i = 1; i < n - 1; ++i)
        {
            int one = (v[i] != v[i + 1]) + ((i >= 2) ? (dp[i - 2]) : (0));
            int two = dp[i - 1];
            dp[i] = max(one, two);
        }
        cout << dp[n - 2];
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
