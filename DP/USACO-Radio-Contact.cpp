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
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INT_MAX));
    pair<ll, ll> xx, yy; cin >> xx.ff >> xx.ss >> yy.ff >> yy.ss;
    string a, b; cin >> a >> b;
    vector<pll> pos1(n + 1), pos2(m + 1);
    pos1[0] = xx; pos2[0] = yy;
    // Function
    auto upd = [&](pll t, char ch) {
        if(ch == 'N') t.ss++;
        if(ch == 'S') t.ss--;
        if(ch == 'E') t.ff++;
        if(ch == 'W') t.ff--;
        return t;
    };
    //
    for(int i = 1; i <= n; ++i) pos1[i] = upd(pos1[i - 1], a[i - 1]);
    for(int i = 1; i <= m; ++i) pos2[i] = upd(pos2[i - 1], b[i - 1]);
    // Function
    auto dis = [&](pll t1, pll t2) {
        ll x = t1.ff - t2.ff, y = t1.ss - t2.ss;
        x *= x; y *= y;
        return x + y;
    };
    //
    for(int i = n; i >= 0; --i) {
        for(int j = m; j >= 0; --j) {
            if(i == n && j == m) dp[i][j] = 0;
            else if(i == n) {
                dp[i][j] = dis(pos1[n], pos2[j + 1]) + dp[i][j + 1];
            }
            else if(j == m) dp[i][j] = dis(pos1[i + 1], pos2[m]) + dp[i + 1][j];
            else {
                dp[i][j] = min(dis(pos1[i + 1], pos2[j]) + dp[i + 1][j], dis(pos1[i], pos2[j + 1]) + dp[i][j + 1]);
                dp[i][j] = min(dp[i][j], dis(pos1[i + 1], pos2[j + 1]) + dp[i + 1][j + 1]);
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
