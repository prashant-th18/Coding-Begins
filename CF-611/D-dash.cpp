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
    int n, m; cin >> n >> m;
    vector<ll> v(n);
    map<ll, bool> vis;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vis[v[i]] = true;
    }
    set<pll> st;
    sort(v.begin(), v.end());
    for(int i = 1; i < n; ++i) {
        if(v[i - 1] + 1 == v[i]) continue;
        st.insert(pll(1, v[i - 1] + 1));
        st.insert(pll(1, v[i] - 1));
        vis[v[i - 1] + 1] = true;
        vis[v[i] - 1] = true;
    }
    st.insert(pll(1, v[0] - 1)); vis[v[0] - 1] = true;
    st.insert(pll(1, v[n - 1] + 1)); vis[v[n - 1] + 1] = true;
    vector<int> ans;
    ll sum = 0;
    for(int i = 0; i < m; ++i) {
        auto p = *st.begin(); st.erase(st.begin());
        sum += p.ff;
        ans.push_back(p.ss);
        ll elem = p.ss;
        if(!vis.count(elem - 1)) {
            st.insert(pll(p.ff + 1, elem - 1)); vis[elem - 1] = true;
        }
        else if(!vis.count(elem + 1)) {
            st.insert(pll(p.ff + 1, elem + 1)); vis[elem + 1] = true;
        }
    }
    cout << sum << '\n';
    for(auto& val : ans) cout << val << ' ';
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
