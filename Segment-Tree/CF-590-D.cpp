#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

int n;
string p, ev = "abcdefghijklmnopqrstuvwxyz";
vector<bool> vis;
vector<set<char>> t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        set<char> st;
        st.insert(p[s]);
        t[in] = st;
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        merge(all(t[2 * in]), all(t[2 * in + 1]), inserter(t[in], t[in].begin()));
    }
}
void update(int in, int s, int e, int pos, char nval) {
    if(s == e) {
        t[in].erase(p[s]);
        t[in].insert(nval);
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) update(2 * in, s, mid, pos, nval);
        else update(2 * in + 1, mid + 1, e, pos, nval);
        t[in].erase(p[pos]);
        t[in].insert(nval);
        bool flag = ((t[2 * in].count(p[pos])) || (t[2 * in + 1].count(p[pos])));
        if(flag) t[in].insert(p[pos]);
    }
}
void query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return;
    if(s == qs && e == qe) {
        for(char& ch: ev) {
            if(t[in].count(ch)) vis[ch - 'a'] = true;
        }
        return;
    }
    int mid = (s + e) / 2;
    query(2 * in, s, mid, qs, min(qe, mid));
    query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe);
}
// *-> KISS*
int solve() {
    cin >> p;
    n = sz(p);
    t.assign(4 * n, set<char>());
    build();
    int m; cin >> m;
    while(m--) {
        int tt; cin >> tt;
        if(tt == 1) {
            int i; cin >> i;
            char ch; cin >> ch;
            update(1, 0, n - 1, i - 1, ch);
            p[i - 1] = ch;
        }
        else {
            int i, j; cin >> i >> j;
            --i; --j;
            vis.assign(26, false);
            query(1, 0, n - 1, i, j);
            int c = 0;
            for(int ii = 0; ii < 26; ++ii) c += vis[ii];
            cout << c << '\n';
        }
    }
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
        if (solve())
        {
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
