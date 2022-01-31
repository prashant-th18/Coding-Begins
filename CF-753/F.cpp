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
    int n, m; cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<ll>> dis(n, vector<ll>(m, 0));
    auto change = [&](ll i, ll j) -> pair<ll, ll>
    {
        if(v[i][j] == 'U') --i;
        else if(v[i][j] == 'D') ++i;
        else if(v[i][j] == 'R') ++j;
        else --j;
        return pair(i, j);
    };
    function<ll(ll, ll)> dfs = [&](ll i, ll j) -> ll
    {
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        else
        {
            if(vis[i][j]) return dis[i][j];
            else
            {
                auto p = change(i, j);
                vis[i][j] = true;
                return dis[i][j] = 1 + dfs(p.ff, p.ss);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!vis[i][j])
            {
                dfs(i, j);
            }
        }
    }
    int x = 0, y = 0, maxdis = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(dis[i][j] > maxdis)
            {
                maxdis = dis[i][j];
                x = i + 1, y = j + 1;
            }
        }
    }
    cout << x << ' ' << y << ' ' << maxdis;
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
}
// -> Keep It Simple Stupid!
