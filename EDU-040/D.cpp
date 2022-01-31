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
int solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<vector<int>> v(n + 1);
    vector<bool> vis(n + 1, false);
    vector<vector<bool>> mat(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        mat[a][b] = mat[b][a] = true;
        v[a].push_back(b); v[b].push_back(a);
    }
    auto f = [&](int node, vector<int>& d) -> void
    {
        vis[node] = true; 
        queue<int> q; q.push(node);
        d[node] = 0;
        while(!q.empty())
        {
            int f_ = q.front(); q.pop();
            for(const auto& val : v[f_])
            {
                if(!vis[val])
                {
                    d[val] = 1 + d[f_];
                    vis[val] = true; q.push(val);
                }
            }
        }
    };
    vector<int> sdis(n + 1, 0), tdis(n + 1, 0);
    f(s, sdis);
    vis.assign(n + 1, false);
    f(t, tdis);
    int c = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(i == j || mat[i][j]) continue;
            else
            {
                // we are making a edge between i and j
                int di = 1;
                di += (min(sdis[i] + tdis[j], sdis[j] + tdis[i]));
                if(di >= sdis[t]) ++c;
            }
        }
    }
    cout << c / 2;
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
