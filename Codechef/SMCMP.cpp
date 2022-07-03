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

// *-> KISS*
int solve() {
    int n, q; cin >> n >> q;
    vector<int> rank(n + 1, 0), par(n + 1, -1);
    auto find = [&](int a) {
        vector<int> temp;
        while(par[a] > 0) {
            temp.push_back(a);
            a = par[a];
        }
        for(auto val : temp) par[val] = a;
        return a;
    };
    auto un = [&](int a, int b) {
        a = find(a), b = find(b);
        if(a != b) {
            if(rank[a] > rank[b]) {
                par[b] = a;
                rank[a] += rank[b];
            }
            else {
                par[a] = b;
                rank[b] += rank[a];
            }
        }
    };
    while(q--) {
        int t, u, v; cin >> t >> u >> v;
        if(t == 1) {
            un(u, v);
        }
        else {
            if(find(u) == find(v)) cout << "Yes\n";
            else cout << "No\n";
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
