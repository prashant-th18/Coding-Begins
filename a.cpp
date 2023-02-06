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

// *-> KISS*
int solve() {
    int n, k, p; cin >> n >> k >> p;
    vector<ll> a(n), b(k);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    
    sort(all(a));
    sort(all(b));
    
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LLONG_MAX));
    
    for(int i = 0; i <= k; ++i) dp[n][i] = 0;
        
    for(int i = n - 1; i >= 0; --i) {
        for(int j = k - 1; j >= 0; --j) {
            dp[i][j] = max(abs(a[i] - b[j]) + abs(b[j] - p), dp[i + 1][j + 1]);
            
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    cout << dp[0][0];
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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