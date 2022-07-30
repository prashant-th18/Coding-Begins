#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1000000));
    // Base Case
    for(int i = n - 1; i >= 0; --i) {
        for(int k = 1; k <= n; ++k) {
            // Break-Out at i
            int till = 0;
            for(int j = i; j < n; ++j) {
                till += ((j - i) != v[j]);
                if(k != 1) dp[i][k] = min(dp[i][k], till + dp[j + 1][k - 1]);
            }
            if(k == 1) dp[i][k] = till;
        }
    }
    cout << dp[0][1];
    for(int i = 2; i <= n; ++i) cout << '\n' << dp[0][i];
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
