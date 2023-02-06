#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// Use -> unordered_map<key_type, value_type, custom_hash> mp;

int n, m;
vector<ll> v;
vector<ll> t;
void update(int in, int s, int e, int index, int nval) {
    if(s == e) {
        t[in] = nval;
    }
    else {
        int mid = (s + e) >> 1;
        if(index <= mid) {
            update(2 * in, s, mid, index, nval);
        }
        else {
            update(2 * in + 1, mid + 1, e, index, nval);
        }
        t[in] = t[2 * in] ^ t[2 * in + 1];
    }
}
ll query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return 0;
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) >> 1;
    return query(2 * in, s, mid, qs, min(mid, qe)) ^ 
           query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe);
}
using pll = pair<ll, ll>;
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n, 0);
    for(auto& val : v) cin >> val;
    
    vector<ll> pref(n);
    for(int i = 0; i < n; ++i) {
        if(i == 0) pref[i] = v[i];
        else {
            pref[i] = v[i] ^ pref[i - 1];
        }
    }
    cin >> m;
    vector<vector<pll>> rm(n);
    for(int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        --l, --r;
        rm[r].push_back({l, i});
    }
    t.assign(4 * n, 0);
    unordered_map<int, int, custom_hash> last;
    vector<int> ans(m, 0);
    for(int i = 0; i < n; ++i) {
        vector<pll>& h = rm[i];
        if(!last.count(v[i])) {
            last[v[i]] = i;
            update(1, 0, n - 1, i, v[i]);
        }
        else {
            update(1, 0, n - 1, last[v[i]], 0);
            update(1, 0, n - 1, i, v[i]);
            last[v[i]] = i;
        }
        for(int j = 0; j < sz(h); ++j) {
            int l = h[j].ff;
            ll l1 = (l == 0) ? (pref[i]) : (pref[i] ^ pref[l - 1]);
            ll l2 = query(1, 0, n - 1, l, i);
            ans[h[j].ss] = l1 ^ l2;
        }
    }
    for(int i = 0; i < m; ++i) cout << ans[i] << '\n';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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