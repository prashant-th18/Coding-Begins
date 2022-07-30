#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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

int n, m;
vector<vector<int>> v;
vector<vector<int>> t;
vector<bool> vis;
vector<ll> c, order, scc;
void dfs(int node) {
    vis[node] = true;
    for(const auto& val : v[node]) {
        if(!vis[val]) dfs(val);
    }
    order.push_back(node);
}
void dfs1(int node) {
    vis[node] = true;
    scc.push_back(node);
    for(const auto& val : t[node]) {
        if(!vis[val]) {
            dfs1(val);
        }
    }
}
template<typename T>
T binexp(T a, T b) {
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n + 1, vector<int>());
    t = v;
    c.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i + 1];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        t[b].push_back(a);
    }
    vis.assign(n + 1, false);
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i);
    }
    vis.clear();
    vis.assign(n + 1, false);
    ll res = 1, sum = 0;
    for(int i = sz(order) - 1; i >= 0; --i) {
        debug(order[i]);
        if(!vis[order[i]]) {
            dfs1(order[i]);
            debug("Yay");
            ll mini = LLONG_MAX, cnt = 0;
            for(auto& val : scc) {
                if(c[val] == mini) ++cnt;
                else if(c[val] < mini) mini = c[val], cnt = 1;
            }
            assert(cnt > 0);
            debug("Yay?");
            scc.clear();
            res = res * cnt % MOD;
            sum += mini;
            debug(res, sum);
        }
    }
    cout << sum << ' ' << res;
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

        if (solve()) {
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
