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
int n, m;
vector<vector<bool>> vis;
vector<vector<int>> v;
bool valid(int i, int j)
{
    if(i >= 0 && j >= 0 && i < n && j < m && !vis[i][j]) return true;
    return false;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int num = 2)
{
    vis[x][y] = true;
    v[x][y] = num;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(valid(nx, ny))
        {
            dfs(nx, ny, 3 - num);
        }
    }
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n, vector<int>(m, -1));
    vis.assign(n, vector<bool>(m, false));
    int x, y; cin >> x >> y;
    --x, --y; vis[x][y] = true;
    v[x][y] = 1;
    int sx = x, sy = y;
    cin >> x >> y; --x, --y; vis[x][y] = true;
    v[x][y] = 2;
    dfs(x, y);
    for (int i = 0; i < 4; i++) {
        int nx = sx + dx[i], ny = sy + dy[i];
        if(0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1)
        {
            if(v[nx][ny] == 1) v[nx][ny] = 3;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
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
