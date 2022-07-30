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
const ll INF = (ll)1e13;

// *-> KISS*
int solve() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<vector<ll>> mat(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    vector<vector<ll>> chg(m, vector<ll>(m, INF));
    // chg[i][j] -> minimum cost to go from "i" to "j"
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            chg[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k_ = 0; k_ < m; k_++) {
                if(chg[j][i] != INF && chg[i][k_] != INF) chg[j][k_] = min(chg[j][k_], chg[j][i] + chg[i][k_]);
            }
        }
    }
    vector<vector<ll>> pre(n + 1, vector<ll>(m, INF));
    for (int j = 0; j < m; j++) {
        pre[0][j] = 0;
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            pre[i + 1][j] = pre[i][j] + chg[s[i] - 'a'][j];
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m, INF));
    for (int j = 0; j < m; j++) {
        dp[0][j] = 0;
    }
    vector<ll> minn(n + 1, INF);
    minn[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; j++) {
            if(i >= k) {
                dp[i][j] = pre[i][j] - pre[i - k][j] + minn[i - k];
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + chg[s[i - 1] - 'a'][j]);
            minn[i] = min(minn[i], dp[i][j]);
        }
    }
    cout << minn[n];
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
