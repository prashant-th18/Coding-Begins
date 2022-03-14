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
#define MOD 1000000007
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
struct edge {
    int p, flag, index;
    bool operator<(const edge& other) const
    {
        return make_tuple(p, flag, index) < make_tuple(other.p, other.flag, other.index);
    }
};
// *-> KISS*
int solve() {
    int n; cin >> n;
    set<edge> st;
    vector<int> ind(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        st.insert({l, -1, i});
        st.insert({r, 1, i});
    }
    int how {}, cnt {};
    for(const auto& [x, y, z] : st)
    {
        if(y == -1)
        {
            ++how;
            ind[z] = cnt % 2;
        }
        else
        {
            --how;
            if(how == 0) ++cnt;
        }
    }
    int c = count(all(ind), 0);
    if(c == 0 || c == n) cout << -1;
    else
    {
        for(auto val : ind) cout << val + 1 << ' ';
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
