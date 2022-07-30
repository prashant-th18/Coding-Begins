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

int MAXX;
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3601, INT_MIN)));
    // dp[i][j][k] -> Till index "i", I have chosen "j" numbers such that on multiplication of those "j"
    // numbers my power of "5" is "k", what is the maximum power of "2" I can get
    // Base Case
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            ll t = v[i - 1];
            ll p2 = 0, p5 = 0;
            while(t % 2 == 0) t /= 2, ++p2;
            while(t % 5 == 0) t /= 5, ++p5;
            if(j == 1) {
                // Okay, we have to select only one number
                for(int l = 0; l <= 3600; ++l) {
                    if(l == p5) {
                        dp[i][j][l] = max(dp[i - 1][j][l], dp[i - 1][j - 1][l - p5] + p2);
                    }
                    else {
                        dp[i][j][l] = dp[i - 1][j][l];
                    }
                }
            }
            else {
                for(int l = 0; l <= 3600; ++l) {
                    if(l - p5 >= 0) dp[i][j][l] = dp[i - 1][j - 1][l - p5] + p2;
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 3600; ++i) ans = max(ans, min(dp[n][k][i], (ll)i));
    cout << ans;
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
