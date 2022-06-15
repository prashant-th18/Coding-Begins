#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
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

// *-> KISS*
int solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<int> par(n + 1, -1);
    vector<int> R(n + 1, 1);
    auto find = [&](int node) {
          vector<int> t;
          while(par[node] > 0) {
              t.push_back(node);
              node = par[node];
          }
          for (int i = 0; i < sz(t); i++) {
              par[t[i]] = node;
          }
          return node;
    };
    auto un = [&](int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(R[a] > R[b]) {
            R[a] += R[b];
            par[b] = a;
        }
        else {
            R[b] += R[a];
            par[a] = b;
        }
        return true;
    };
    set<vector<ll>> st;
    for(int i = 0; i < m; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        vector<ll> temp = {abs(c - k), a , b};
        st.insert(temp);
    }
    while(sz(st) != 0) {
        vector<ll> temp = st.begin();
        st.erase(st.begin());

    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
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
