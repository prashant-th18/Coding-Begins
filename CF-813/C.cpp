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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<bool> s(n + 1, false);
    s[n - 1] = true; s[n] = true;
    for(int i = n - 2; i >= 0; --i) {
        s[i] = s[i + 1] && (v[i] <= v[i + 1]);
    }
    int ans = n + 1;
    if(s[0]) ans = 0;
    set<int> st1, st2;
    vector<vector<int>> pos(n + 1);
    for(int i = 0; i < n; ++i) {
        pos[v[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
        st1.insert(v[i]);
        if(!st2.count(i)) {
            for(auto& val : pos[v[i]]) st2.insert(val);
        }
        auto it = st2.upper_bound(i);
        if(it == st2.end() && s[i + 1]) ans = min(ans, sz(st1));
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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
