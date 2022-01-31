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
int solve() {
    char a, b; int sx, tx;
    cin >> a >> sx >> b >> tx;
    int sy = (a - 'a') + 1, ty = (b - 'a') + 1;
    int n = 8;
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 0));
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    auto isValid = [&](int x, int y) -> bool
    {
        if(x < 1 || x > n || y < 1 || y > n || vis[x][y]) return false;

        return true;
    };
    auto fun = [&]() -> void
    {
        queue<pair<int, int>> q; q.push({sx, sy}); vis[sx][sy] = true; dis[sx][sy] = 0;
        while(!q.empty())
        {
            int fx = q.front().ff;
            int fy = q.front().ss;
            q.pop();
            for(int i = 0; i < 8; ++i)
            {
                int nx = fx + dx[i];
                int ny = fy + dy[i];
                if(isValid(nx, ny))
                {
                    vis[nx][ny] = true;
                    dis[nx][ny] = 1 + dis[fx][fy];
                    q.push({nx, ny});
                    if(nx == tx && ny == ty)
                    {
                        cout << dis[nx][ny]; return;
                    }
                }
            }
        }
    };
    fun();
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
