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
    int n, q; cin >> n >> q;
    vector<vector<int>> v(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> size(n + 1, 0), index(n + 1, 0);
    vector<int> order;
    for (int i = 0; i < n - 1; i++) {
        int a; cin >> a;
        v[i + 2].push_back(a);
        v[a].push_back(i + 2);
    }
    auto dfs = y_combinator([&](auto f, int node) -> int
    {
        vis[node] = true;
        order.push_back(node);
        index[node] = sz(order) - 1;
        vector<int> children;
        for(const auto& val : v[node])
        {
            if(!vis[val]) children.push_back(val);
        }
        sort(children.begin(), children.end());
        size[node]++; // myself
        for(const auto& val : children)
        {
            size[node] += f(val);
        }
        return size[node];
    });
    dfs(1);
    while(q--)
    {
        int ui, ki; cin >> ui >> ki;
        int ind = index[ui];
        --ki;
        if(ki >= size[ui])
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << order[ind + ki] << '\n';
        }
    }
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
