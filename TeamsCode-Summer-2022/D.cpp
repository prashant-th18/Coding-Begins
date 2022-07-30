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
    ll a, b, m; cin >> a >> b >> m;
    vector<ll> v;
    for(ll i = 1; i < 33; ++i) {
        v.push_back((1LL << i) - 1);
    }
    int ind = lower_bound(all(v), m) - begin(v);
    ll elem = v[ind];
    // v[i], v[i] + (1LL << i), v[i] + 2 * (1LL << i) ..
    ll aa = v[ind], dif = (1LL << ind);
    ll last = (b - aa + dif - 1) / dif + 1;
    while(aa + (last - 1) * dif > b) -- last;
    ll first = (a - 1 - aa + dif - 1) / dif + 1;
    while(aa + (first - 1) * dif > a - 1) -- first;
    cout << max(0LL, last - first);
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
