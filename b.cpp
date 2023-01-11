#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll add(ll a, ll b) {
    return (a + b) % MOD;
}
ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}
// *-> KISS*
int solve() {
    int n, a, b, k; cin >> n >> a >> b >> k;
    // n -> floors
    // a -> starting floor
    // b -> secret floor
    // k -> How many jumps
    vector<vector<ll>> dp(n + 2, vector<ll>(k + 1, 0));
    // Base Case
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = (i != b);
    }
    for(int j = 1; j <= k; ++j) {
        vector<ll> pre(n + 2, 0), suf(n + 2, 0);
        for(int i = 1; i <= n; ++i) {
            pre[i] = add(pre[i - 1], dp[i][j - 1]);
        }
        
        for(int i = n; i >= 1; --i) {
            suf[i] = add(suf[i + 1], dp[i][j - 1]);
        }
        
        for(int i = 1; i <= n; ++i) {
            int dis = abs(i - b) - 1;
            if(dis > 0) {
                // Left
                // [i - dis - 1 ... i - 1]
                int l = max(i - dis - 1, 0);
                int r = i - 1;
                dp[i][j] = add(dp[i][j], sub(pre[r], pre[l]));
                
                // Right
                l = i + 1;
                r = min(n + 1, i + dis + 1);
                dp[i][j] = add(dp[i][j], sub(suf[l], suf[r]));
            }
        }
    }
    cout << dp[a][k];
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        #ifdef LOCAL
            cout << "##################" << '\n';
        #endif
        if (solve()) {
            break;
        }
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
// -> Keep It Simple Stupid!