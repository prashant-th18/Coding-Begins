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
vector<bool> vis;
vector<array<bool, 2>> vi;
vector<ll> dis;
vector<array<ll, 2>> ans;
void dist(int node, int d = 0) {
    vis[node] = true;
    dis[node] = d;
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        int t = q.front(); q.pop();
        for(const auto& val : v[t]) {
            if(!vis[val]) {
                vis[val] = true;
                dis[val] = 1 + dis[t];
                q.push(val);
            }
        }
    }
}
ll calc(int node, int c) {
    if(ans[node][c] != INT_MAX) return ans[node][c];
    ans[node][c] = dis[node];
    if(c == 0) {
        return ans[node][c];
    }
    vector<int> less, more;
    for(const auto& val : v[node]) {
        if(dis[node] < dis[val]) {
            less.push_back(val);
        }
        else more.push_back(val);
    }
    for(auto& val : more) {
        ans[node][c] = min(ans[node][c], calc(val, 0));
    }
    for(auto& val : less) {
        ans[node][c] = min(ans[node][c], calc(val, c));
    }
    return ans[node][c];
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    // 
    dis.assign(n + 1, INT_MAX);
    vis.assign(n + 1, false);
    dist(1);
    vi.assign(n + 1, {false, false});
    ans.assign(n + 1, {INT_MAX, INT_MAX});
    ans[1][0] = ans[1][1] = 0;
    vi[1][0] = vi[1][1] = true;
    for(int i = 2; i <= n; ++i) {
        calc(i, 1);
    }
    for(int i = 1; i <= n; ++i) cout << ans[i][1] << ' ';
    v.clear();
    vi.clear();
    dis.clear();
    vis.clear();
    ans.clear();
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

