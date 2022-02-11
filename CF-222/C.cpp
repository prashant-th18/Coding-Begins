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

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}

int n, m;
vector<vector<char>> v;
vector<vector<bool>> vis;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || v[i][j] == '#') return 0;
    else if(vis[i][j]) return 1;
    return 2;
}
vector<pair<int, int>> d;
void dfs(int i, int j)
{
    d.push_back(pair(i, j));
    vis[i][j] = true;
    for(int ii = 0; ii < 4; ++ii)
    {
        int nx = i + dx[ii], ny = j + dy[ii];
        int get_valid = valid(nx, ny);
        if(get_valid == 2)
        {
            dfs(nx, ny);
        }
    }
}
// *-> KISS*
int solve() {
    int k; cin >> n >> m >> k;
    v = vector<vector<char>>(n, vector<char>(m, '.'));
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    bool flag = false;
    for(int i = 0; i < n && !flag; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(v[i][j] == '.')
            {
                dfs(i, j);
                flag = true;
                break;
            }
        }
    }
    for(int i = sz(d) - 1; i >= 0 && k; --i, --k)
    {
        v[d[i].ff][d[i].ss] = 'X';
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) cout << v[i][j];
        cout << '\n';
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
    return 0;
}
// ->  It Simple Stupid!
