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

#ifdef LOCAL
    void debug_print(string s) {
        cerr << "\"" << s << "\"";
    }

    void debug_print(const char* s) {
        debug_print((string)s);
    }

    void debug_print(bool val) {
        cerr << (val ? "true" : "false");
    }

    void debug_print(int val) {
        cerr << val;
    }

    void debug_print(ll val) {
        cerr << val;
    }

    void debug_print(double val) {
        cerr << val;
    }

    template<typename F, typename S>
    void debug_print(pair<F, S> val) {
        cerr << "(";
        debug_print(val.first);
        cerr << ", ";
        debug_print(val.second);
        cerr << ")";
    }

    void debug_print(vector<bool> val) {
        cerr << "{";
        bool first = true;
        for (bool x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    template<typename T>
    void debug_print(T val) {
        cerr << "{";
        bool first = true;
        for (const auto &x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    void debug_print_collection() {
        cerr << endl;
    }

    template<typename First, typename... Args>
    void debug_print_collection(First val, Args... args) {
        cerr << " ";
        debug_print(val);
        debug_print_collection(args...);
    }

#define debug(...) cerr << "@@@ " << #__VA_ARGS__ << " ="; debug_print_collection(__VA_ARGS__);

#else
    #define debug(...) 
#endif

vector<vector<int>> v;
vector<bool> vis;
vector<int> a, b;
vector<array<int, 3>> dp;
void dfs(int node, int p) {
    vis[node] = true;
    // Either make it 0, or 1, or don't change
    // 0
    auto fun = [&](int in) -> int {
          int res = 0;
          for(const auto& val : v[node]) {
              if(!vis[val]) dfs(val, node);
              if(val != p) {
                  if(in == 2) res += min({dp[val][0], dp[val][1], dp[val][2]});
                  else res += (dp[val][in] - 1);
              }
          }
          return res;
    };
    if(a[node] == 0) {
        if(b[node] == 0) {
            int z = 1 + fun(0);
            int o = 1 + z;
            dp[node][0] = z; dp[node][1] = o;
            dp[node][2] = fun(2);
        }
        else {
            int o = 1 + fun(1);
            int z = 1 + o;
            dp[node][0] = z; dp[node][1] = o;
            dp[node][2] = o;
        }
    }
    else {
        if(b[node] == 0) {
            int z = 1 + fun(0);
            int o = 1 + z;
            dp[node][0] = z; dp[node][1] = o;
            dp[node][2] = z;
        }
        else {
            int o = 1 + fun(1);
            int z = 1 + o;
            dp[node][0] = z; dp[node][1] = o;
            dp[node][2] = fun(2);
        }
    }
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    a.assign(n + 1, 0); b.assign(n + 1, 0);
    dp.assign(n + 1, {0, 0, 0});
    for(int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i + 1];
    }
    for(int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, -1);
    cout << min({dp[1][0], dp[1][1], dp[1][2]});
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
