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
#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}
// *-> KISS*
int N = 3e5;
vector<vector<int>> v(N);
vector<int> vis(N, 0);
vector<int> parent(N);
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
    ll n; cin >> n;
    vector<ll> c(n);
    for (ll &val : c) {
        cin >> val;
    }
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        v[i + 1].push_back(t);
    }
    ll c_start = -1, c_end = -1;
    // Directed Graph
    auto dfs = y_combinator([&](auto dfs, ll node) -> int // 1 for cycle, 0 for simple, -1 for earlier done
    {
       vis[node] = 1; // In-Queue
       for(const auto& val : v[node])
       {
           if(vis[val] == 1)
           {
               // Cycle Found
               parent[val] = node;
               c_start = node; c_end = val;
               vis[node] = 2;
               return -1;
           }
           else if(vis[val] == 0)
           {
               parent[val] = node;
               if(dfs(val) == -1) { vis[node] = 2; return -1; }
               else
               {
                   vis[node] = 2;
                   return dfs(val);
               }
           }
           else
           {
               vis[node] = 2;
               return -2;
           }
       }
       vis[node] = 2;
       return c[node - 1];
    });
    ll sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        c_start = c_end = -1;
        if(vis[i] == 0)
        {
            ll g = dfs(i);
            if(g == -1)
            {
                ll mini = c[c_end - 1];
                for(ll j = c_start; j != c_end; j = parent[j])
                {
                    debug(j);
                    mini = min(mini, c[j - 1]);
                }
                debug(i);
                sum += mini;
            }
            else if(g != -2)
            {
                sum += g;
            }
        }
    }
    cout << sum;
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
