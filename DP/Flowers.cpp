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
    ll maxx = 0;
    vector<ll> h(n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < n; ++i) cin >> v[i];
    set<pll> st;
    for(int i = n - 1; i >= 0; --i) {
        pll t = pair(h[i], v[i]);
        maxx = max(maxx, t.ss);
        auto it = st.upper_bound(t);
        if(it == st.end()) {
            st.insert(t);
        }
        else {
            t.ss += (*it).ss;
            st.insert(t);
            maxx = max(maxx, t.ss);
            it = st.find(t);
            if(it == st.begin()) continue;
            else {
                --it;
                vector<pll> toErase;
                while(it != st.begin()) {
                    if((*it).ss <= t.ss) {
                        toErase.push_back(*it);
                        --it;
                    }
                    else {
                        break;
                    }
                }
                if((*it).ss <= t.ss) toErase.push_back(*it);
                for(auto& val : toErase) st.erase(val);
            }
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
