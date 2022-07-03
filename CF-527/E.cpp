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

int n, m, x = -1, mh = -1;
vector<vector<int>> v;
vector<bool> vis;
vector<int> c;
vector<pair<int, int>> every;
int dfs(int node, int p = -1) {
    int maxx = 0;
    vis[node] = true;
    c.push_back(node);
    for(const auto& val : v[node]) {
        if(val != p) maxx = max(maxx, 1 + dfs(val, node));
    }
    return maxx;
}
void fun(int node) {
    dfs(node);
    auto cc = c;
    vector<int> h(sz(cc));
    auto p = pair(INT_MAX, -1);
    for (int i = 0; i < sz(cc); i++) {
        h[i] = dfs(cc[i], -1);
        if(h[i] < p.first) {
            p = {h[i], cc[i]};
        }
    }
    every.push_back(p);
    c.clear();
}
void dia(int node, int h, int p = -1) {
    if(h > mh) {
        mh = h;
        x = node;
    }
    for(const auto& val : v[node]) {
        if(val != p) dia(val, h + 1, node);
    }
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            fun(i);
        }
    }
    sort(every.begin(), every.end(), [&](pair<int, int> a, pair<int, int> b) {
       return a.first > b.first; 
    });
    vector<pair<int, int>> ans;
    for(int i = 1; i < sz(every); ++i) {
        ans.push_back({every[i].ss, every[0].ss});
        v[every[i].ss].push_back(every[0].ss);
        v[every[0].ss].push_back(every[i].ss);
    }
    dia(1, 0);
    dia(x, 0);
    cout << mh << '\n';
    for(auto [xx, y] : ans) {
        cout << xx << ' ' << y << '\n';
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
