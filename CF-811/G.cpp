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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<vector<int>> v;
vector<int> blue, red;
vector<vector<int>> lca;
vector<array<ll, 2>> pre; // 0 -> blue, 1 -> red
vector<int> depth, ans;
void dfs(int node, int d, ll bl, ll re, int p) {
    depth[node] = d;
    lca[node][0] = p;
    pre[node][0] = bl; pre[node][1] = re;
    for(const auto& val : v[node]) {
        if(val != p) {
            dfs(val, d + 1, bl + blue[val], re + red[val], node);
        }
    }
}
void init() {
    for(int j = 1; j < 32; ++j) {
        for(int i = 1; i <= n; ++i) {
            int p = lca[i][j - 1];
            if(p != -1) {
                p = lca[p][j - 1];
            }
            lca[i][j] = p;
        }
    }
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n + 1, vector<int>());
    blue.assign(n + 1, 0);
    red.assign(n + 1, 0);
    lca.assign(n + 1, vector<int>(32, -1));
    pre.assign(n + 1, {0, 0});
    depth.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int p, a, b; cin >> p >> a >> b;
        v[p].push_back(i + 2);
        v[i + 2].push_back(p);
        blue[i + 2] = a;
        red[i + 2] = b;
    }
    dfs(1, 0, 0, 0, -1);
    init();
    for(int i = 2; i <= n; ++i) {
        int s = 0, e = depth[i];
        int an = 0;
        while(s <= e) {
            int mid = midpoint(s, e);
            ll dif = depth[i] - mid;
            int elem = i;
            for(int j = 0; j < 31; ++j) {
                if((dif >> j) & 1) {
                    elem = lca[elem][j];
                }
            }
            if(pre[elem][1] <= pre[i][0]) {
                an = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        ans[i] = an;
    }
    for(int i = 2; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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
