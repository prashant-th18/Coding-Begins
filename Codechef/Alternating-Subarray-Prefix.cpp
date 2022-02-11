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
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<ll> dp(n, 0);
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; --i)
        {
            int nxt = 1;
            if(v[i] * v[i + 1] < 0) nxt += dp[i + 1];
            dp[i] = nxt;
        }
        for(auto val : dp) cout << val << ' ';
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
