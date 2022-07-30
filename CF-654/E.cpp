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
    ll n, p; cin >> n >> p;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> t;
    for(ll i = 1; i <= 2000; ++i) {
        // Verify if "i" is good or not
        ll elem = 0, x = i;
        ll ans = 1;
        ll j = 0;
        while(j < n) {
            if(v[j] <= x) ++j, ++elem;
            else {
                if(elem == 0) {
                    break;
                }
                else {
                    ans = ans * elem % p;
                    --elem;
                    ++x;
                }
            }
        }
        if(j == n) {
            while(elem) ans = ans * elem % p, elem--;
            if(ans) t.push_back(i);
        }
    }
    cout << sz(t) << '\n';
    for(auto& val : t) cout << val << ' ';
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
