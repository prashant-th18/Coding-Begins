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
// *-> KISS*
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
int solve() {
    int n; cin >> n;
    vector<vector<int>> v(n + 1);
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        edges[i] = pair(a, b);
    }
    vector<int> col(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> col[i + 1];
    }
    auto dfs = y_combinator([&](auto f, int node, int parent) -> bool
    {
        for(const auto& val : v[node])
        {
            if(val == parent) continue;
            else
            {
                if(col[val] != col[node]) return false;
                else
                {
                    if(!f(val, node)) return false;
                }
            }
        }
        return true;
    });
    auto fun = [&](int node, int other) -> int // 0 means iske apne children ke saath relations bekaar, 1 means ache
    // -1 niche se glt
    {
        bool flag = true;
        for(const auto& val : v[node])
        {
            if(val != other)
            {
                flag &= dfs(val, node);
            }
        }
        if(flag == false) return -1;
        else
        {
            for(const auto& val : v[node])
            {
                if(val != other && col[val] != col[node]) return 0;
            }
            return 1;
        }
    };
    for(int i = 0; i < n - 1; ++i)
    {
        if(col[edges[i].ff] != col[edges[i].ss])
        {
            // choose edges[i].ff
            // root
            int one = fun(edges[i].ff, edges[i].ss);
            int two = fun(edges[i].ss, edges[i].ff);
            if((one == -1 || two == -1) || (one == 0 && two == 0))
            {
                cout << "NO\n"; return 0;
            }
            else if(one == 1 && two == 1)
            {
                cout << "YES\n" << edges[i].ff; return 0;
            }
            else if(one == 1)
            {
                cout << "YES\n" << edges[i].ss; return 0;
            }
            else if(two == 1)
            {
                cout << "YES\n" << edges[i].ff; return 0;
            }
            else
            {
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES\n" << 1;
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
