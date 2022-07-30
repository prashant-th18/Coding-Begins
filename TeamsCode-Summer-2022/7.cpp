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
    int n, m; cin >> n >> m;
    int mini = min(n, m);
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            v[i][j] = ch == '.' ? 0 : 1;
        }
    }
    vector<ll> pre(mini + 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(v[i][j] == 0) {
                ll elem = min(n - i, j + 1);
                pre[elem]++;
            }
        }
    }
    vector<ll> ans(mini + 1, 0);
    ll tot = 0;
    for(int i = mini; i >= 2; --i) {
        tot += pre[i];
        ans[i] = (1LL * (m - i + 1) * (n - i + 1));
        ans[i] -= tot;
        ans[i] = max(0LL, ans[i]);
    }
    for(int i = 2; i <= mini; ++i) cout << ans[i] << '\n';
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
