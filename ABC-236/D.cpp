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
    vector<vector<ll>> v(2 * n, vector<ll>(2 * n, 0));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            cin >> v[i][j];
            v[j][i] = v[i][j];
        }
    }
    vector<bool> vis(32, false);
    ll ans = -1;
    ll count = 0;
    set<pair<int, int>> st;
    auto fun = y_combinator([&](auto f, ll num, ll res, int c) -> void
    {
        for(int i = num + 1; i < 2 * n; ++i)
        {
            if(!vis[i])
            {
                //if(st.count(pair(i, num))) continue;
                //st.insert(pair(num, i));
                vis[i] = true;
                res ^= v[num][i];
                if(c == n)
                {
                    ++count;
                    ans = max(ans, res); 
                    res ^= v[num][i]; vis[i] = false;
                    return;
                }
                for(int j = i + 1; j < 2 * n; ++j)
                {
                    if(!vis[j])
                    {
                        vis[j] = true;
                        f(j, res,c + 1); 
                        vis[j] = false;
                    }
                }
                res ^= v[num][i]; vis[i] = false;
            }
        }
    });
    for(int i = 0; i < 2 * n; ++i)
    {
        vis[i] = true;
        fun(i, 0, 1);
        vis[i] = false;
    }
    cout << count << endl << endl;
    cout << ans;
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
