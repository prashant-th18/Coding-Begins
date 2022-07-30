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

int n, m;
vector<vector<int>> v;
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<pll> order(n);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        order[i] = pair(t, i + 1);
    }
    sort(order.begin(), order.end());
    vector<int> ans(n + 1, -1);
    for (int i = 0; i < n; i++) {
        int blog = order[i].ss;
        vector<int> t;
        for(const auto& val : v[blog]) {
            if(ans[val] != -1) t.push_back(ans[val]);
        }
        sort(all(t));
        t.resize(unique(all(t)) - t.begin());
        int what = 1;
        for(int j = 0; j < sz(t); ++j) {
            if(t[j] == what) ++what;
            else break;
        }
        if(what == order[i].ff) {
            ans[blog] = what;
        }
        else {
            cout << -1; return 0;
        }
    }
    for(int i = 1; i <= n; ++i) cout << order[i - 1].ss << ' ';
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
