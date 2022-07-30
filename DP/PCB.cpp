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
    set<pll> st;
    int n; cin >> n;
    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        pll temp = pair(v[i].ss, 1);
        auto it = st.lower_bound(temp);
        if(it == st.end()) st.insert(temp);
        else st.insert(pair(v[i].ss, (*it).ss + 1));
        
        it = st.lower_bound(temp);
        temp = *it;
        while(it != st.begin()) {
            --it;
            if((*it).ss <= temp.ss) st.erase(it);
            else break;
            it = st.lower_bound(temp);
        }
    }
    assert(sz(st) > 0);
    cout << (*st.begin()).ss;
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
