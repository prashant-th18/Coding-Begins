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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// use -> auto gcd = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<vector<int>> v(n);
    vector<vector<int>> t(n);
    vector<bool> vis(n, false);
    vector<int> order;
    vector<int> scc;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int next = (arr[i] + i + 1) % n;
        v[i].push_back(next);
        t[next].push_back(i);
    }
    auto dfs1 = y_combinator([&](auto f, int node) -> void
    {
        vis[node] = true;
        for(auto val : v[node])
        {
            if(!vis[val])
            {
                f(val);
            }
        }
        order.push_back(node);
    });
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i]) dfs1(i);
    }
    vis.assign(n, false);
    auto dfs2 = y_combinator([&](auto f, int node) -> void
    {
        vis[node] = true;
        for(auto val : t[node])
        {
            if(!vis[val]) f(val);
        }
        scc.push_back(node);
    });
    int c = 0;
    reverse(all(order));
    for(int i = 0; i < n; ++i)
    {
        if(!vis[order[i]])
        {
            dfs2(order[i]);
            if(sz(scc) != 1)
            {
                c += sz(scc);
            }
            else
            {
                if(arr[scc.back()] % n == n - 1) ++c;  
            }
            scc.clear();
        }
    }
    cout << c;
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
}
// -> Keep It Simple Stupid!

