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

int n;
vector<int> rl;
vector<vector<int>> t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = vector<int>(1, rl[s]);
    }
    else {
        int mid = (s + e) >> 1;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        merge(all(t[2 * in]), all(t[2 * in + 1]), back_inserter(t[in]));
    }
}
ll query(int in, int s, int e, int qs, int qe, ll nval) {
    if(qs > qe) return 0;
    if(s == qs && e == qe) {
        auto it = sz(t[in]) - (upper_bound(all(t[in]), nval, greater<int>()) - begin(t[in]));
        return it;
    }
    int mid = (s + e) >> 1;
    return query(2 * in, s, mid, qs, min(qe, mid), nval) + query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, nval);
}
void rev(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) return;
    int mid = (s + e) >> 1;
    reverse(all(t[in]));
    rev(2 * in, s, mid);
    rev(2 * in + 1, mid + 1, e);
}
// *-> KISS*
int solve() {
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    {
        reverse(all(v));
        rl.assign(n, 0);
        map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            ++mp[v[i]];
            rl[i] = mp[v[i]];
        }
        reverse(all(rl));
        reverse(all(v));
    }
    t.assign(2 * n + 2, vector<int>());
    build();
    rev();
    ll ans = 0;
    map<int, int> mp;
    for(int i = 0; i < n - 1; ++i) {
        ++mp[v[i]];
        ans += query(1, 0, n - 1, i + 1, n - 1, mp[v[i]]);
    }
    cout << ans;
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
