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
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
    for(int i = n; i >= 0; --i) {
        for(int j = n; j >= 0; --j) {
            if(i == n || j == n) dp[i][j] = 0;
            else {
                if (abs(a[i] - b[j]) <= 4) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                dp[i][j] = max({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
            }
        }
    }
    cout << dp[0][0];
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
