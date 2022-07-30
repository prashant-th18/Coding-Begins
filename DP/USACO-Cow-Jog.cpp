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
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    ll n, t; cin >> n >> t;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        v[i] = a + b * t;
    }
    vector<ll> pos;
    for(int i = 0; i < n; ++i) {
        ll elem = v[i];
        ll s = 0, e = sz(pos) - 1;
        ll ans = -1;
        while(s <= e) {
            ll mid = (s + e) >> 1;
            if(pos[mid] < elem) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        if(ans != -1) pos[ans] = elem;
        else pos.push_back(elem);
    }
    cout << sz(pos);
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
