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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll = pair<ll, ll>;

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

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set f;
const int N = 3e5;
int n, m;
vector<vector<pll>> v;
vector<bool> vis;
vector<ll> path(N, 0);
void dfs(int node) {
    vis[node] = true;
    for(const auto& [val, w] : v[node]) {
        if(!vis[val]) {
            ll pre2 = f.order_of_key(val);
            ll pre1 = f.order_of_key(node);
            dfs(val);
            debug(f);
            // "node" ------ "val"
            ll a2 = f.order_of_key(val); // pre2 - a2, val - 1
            ll a1 = f.order_of_key(node);
            debug(node, val);
            debug(pre1, a1);
            debug(pre2, a2);
            ll temp = (val - 1 - (pre2 - a2)) + (pre1 - a1);
            debug(temp);
            path[w] += temp;
        }
    }
    f.erase(node);
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n + 1, vector<pll>());
    vis.assign(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c; cin >> a >> b >> c;
        v[a].push_back(pll(b, c));
        v[b].push_back(pll(a, c));
    }
    for(int i = 1; i <= n; ++i) f.insert(i);
    dfs(1);
    /*for(int i = N - 2; i >= 0; --i) {
        path[i] += path[i + 1];
    }*/
    ll sum = n * (n - 1) / 2;
    cerr << endl;
    for(int i = 1; i <= 4; ++i) cerr << path[i] << ' ';
    while(m--) {
        int q; cin >> q;
        cout << sum - path[q + 1] << ' ';
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
