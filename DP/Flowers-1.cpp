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
    int n; cin >> n;
    vector<ll> h(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll maxx = 0;
    set<pll> st;
    for (int i = 0; i < n; i++) {
        pll t = pair(h[i], v[i]);
        auto it = st.upper_bound(t);
        if(it == st.begin()) {
            st.insert(t);
        }
        else {
            --it;
            t.ss += (*it).ss;
            st.insert(t);
        }
        maxx = max(maxx, t.ss);
        it = st.upper_bound(t);
        while(it != st.end()) {
            if((*it).ss < t.ss) it = st.erase(it);
            else break;
        }
    }
    cout << maxx;
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
