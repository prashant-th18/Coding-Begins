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

inline ll nxt() { ll _; cin >> _; return _; }

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
int N = 1e6;
vector<vector<int>> v(N);
vector<bool> vis(N, false);
vector<int> in(N);
vector<int> low(N);
int solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a = nxt(), b = nxt();
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int timer = 0;
    // First Check if A Bridge is present or not
    // If not, it maybe possible
    // otherwise not at all possible
    map<pair<int, int>, bool> mp;
    function<bool(int node, int parent)> dfs = [&](int node, int parent) -> bool
    {
        bool alpha = false;
        vis[node] = true;
        in[node] = low[node] = timer++;
        for(int val : v[node])
        {
            if(val == parent)
            {
                continue;
            }
            else
            {
                if(!mp.count(pair(val, node)))
                {
                    mp[pair(node, val)] = true;
                }
                if(vis[val])
                {
                    low[node] = min(low[node], in[val]);
                }
                else
                {
                    alpha |= dfs(val, node);
                    if(low[val] > in[node])
                    {
                        alpha = true;
                    }
                    low[node] = min(low[node], low[val]);
                }
            }
        }
        return alpha;
    };
    if(dfs(1, -1))
    {
        cout << 0;
    }
    else
    {
        for(const auto& val : mp)
        {
            cout << val.ff.ff << ' ' << val.ff.ss << '\n';
        }
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
