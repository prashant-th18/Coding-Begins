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
// use -> auto g = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});

// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int index = 0;
    vector<int> ind(n + 1);
    vector<vector<int>> grp(n + 1);
    auto dfs = y_combinator([&](auto f, int node) -> void
    {
        vis[node] = true;
        ind[node] = index;
        grp[index].push_back(node);
        for(const auto& val : v[node])
        {
            if(!vis[val])
            {
                f(val);
            }
        }
    });
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            dfs(i); ++index;
        }
    }
    for (int i = 0; i < index; i++) {
        sort(grp[i].begin(), grp[i].end());
    }
    int maxx = 1, c = 0;
    for(int i = 0; i < index; ++i)
    {
        if(sz(grp[i]) == 0) continue;
        maxx = grp[i].back();
        for(int j = grp[i][0]; j <= maxx; ++j)
        {
            if(ind[j] != ind[maxx])
            {
                int maxi = grp[ind[j]].back();
                int may = ind[j];
                while(sz(grp[may]))
                {
                    ind[grp[may].back()] = ind[maxx];
                    grp[may].pop_back();
                }
                maxx = max(maxx, maxi);
                ++c;
            }
        }
    }
    cout << c;
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
