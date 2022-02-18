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

// *-> KISS*
int n, m, k = 1;
vector<vector<char>> v;
vector<vector<int>> vis;
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0};
bool valid(int x, int y, char ch)
{
    if(x < 0 || x >= n || y < 0 || y >= m || (vis[x][y] != 0) || (v[x][y] != ch)) return false;
    return true;
}
set<pair<int, int>> sides;
void dfs(int x, int y, char ch)
{
    vis[x][y] = k;
    if(ch == 'B' && y == m - 1) sides.insert({x, y});
    else if(ch == 'R' && x == n - 1) sides.insert({x, y});
    for (int i = 0; i < 6; i++) {
        int ni = x + dx[i], nj = y + dy[i];
        if(valid(ni, nj, ch)) dfs(ni, nj, ch);
    }
}
int solve() {
    sides.clear();
    cin >> n;
    m = n;
    int r = 0, b = 0;
    v = vector<vector<char>>(n, vector<char>(m, '.'));
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            b += (v[i][j] == 'B');
            r += (v[i][j] == 'R');
        }
    }
    if(abs(r - b) > 1)
    {
        cout << "Impossible"; return 0;
    }
    for(int i = 0; i < n; ++i) if(v[i][0] == 'B') dfs(i, 0, 'B');
    if(sz(sides) != 0)
    {
        if(sz(sides) > 1) cout << "Impossible";
        else
        {
            cout << "Blue wins";
        }
        return 0;
    }
    for(int j = 0; j < m; ++j)
    {
        if(v[0][j] == 'R') dfs(0, j, 'R');
    }
    if(sz(sides) != 0)
    {
        if(sz(sides) > 1) cout << "Impossible";
        else cout << "Red wins";
        return 0;
    }
    cout << "Nobody wins";
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
        cout << "Case #" << i << ": ";
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
