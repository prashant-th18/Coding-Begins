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

const ll inf = -1e18;
// *-> KISS*
int solve() {
    ll n; cin >> n;
    vector<ll> v(n + 1, 0);
    for(int i = 2; i <= n; ++i) cin >> v[i];
    vector<array<ll, 3>> value(n + 1); // if -1, then infinity
    auto dfs = y_combinator([&](auto f, ll node, int i = 2) -> ll
    {
        if(i == 1) // +
        {
            ll newnum = node + v[node];
            if(newnum > n)
            {
                value[node][i] = v[node];
                return value[node][i];
            }
            else
            {
                if(value[node][i] == 0)
                {
                    // In-Progress
                    value[node][i] = -1;
                    ll ahead = 0;
                    if(value[newnum][3 - i] == -1 || value[newnum][3 - i] == inf) value[newnum][3 - i] = inf, ahead = inf;
                    else ahead = f(newnum, 3 - i);
                    if(ahead == inf)
                    {
                        return value[node][i] = inf;
                    }
                    else
                    {
                        return value[node][i] = v[node] + ahead;
                    }
                }
                else return value[node][i];
            }
        }
        else // -
        {
            ll newnum = node - v[node];
            if(newnum <= 0)
            {
                return value[node][i] = v[node];
            }
            else
            {
                if(value[node][i] == 0)
                {
                      // In-Progress
                      value[node][i] = -1;
                      ll ahead = 0;
                      if(value[newnum][3 - i] == -1 || value[newnum][3 - i] == inf) value[newnum][3 - i] = inf, ahead = inf;
                      else ahead = f(newnum, 3 - i);
                      if(ahead == inf)
                      {
                          return value[node][i] = inf;
                      }
                      else
                      {
                          return value[node][i] = v[node] + ahead;
                      }
                }
                else return value[node][i];
            }
        }
    });
    for(int i = 1; i <= n - 1; ++i)
    {
        ll ahead = 0;
        value[1][1] = -1;
        if(value[i + 1][2] == 0)
        {
            ahead = dfs(i + 1, 2);
        }
        else if(value[i + 1][2] == inf)
        {
            ahead = inf;
        }
        else ahead = value[i + 1][2];
        if(ahead == inf) cout << -1;
        else cout << ahead + i;
        cout << '\n';
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
