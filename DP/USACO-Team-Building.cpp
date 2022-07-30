#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 9;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    ll n, m, K; cin >> n >> m >> K;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend()); sort(b.rbegin(), b.rend());
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(K + 1, 0)));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = 1;
        }
    }
    auto add = [&](ll aa, ll bb) {
        return (aa + bb) % MOD;
    };
    auto sub = [&](ll aa, ll bb) {
        return (aa - bb + MOD) % MOD;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= K; k++) {
                ll op = (a[i - 1] > b[j - 1] ? dp[i - 1][j - 1][k - 1] : 0);
                dp[i][j][k] = op + dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
                dp[i][j][k] = (dp[i][j][k] + MOD) % MOD;
            }
        }
    }
    cout << dp[n][m][K];
    return 0;
}

int32_t main() {
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

