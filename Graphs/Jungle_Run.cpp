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
    int n; cin >> n;
    int srcx, srcy, ex, ey;
    vector<vector<char>> v(n, vector<char>(n, '.'));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'S')
            {
                srcx = i, srcy = j;
            }
            else if(v[i][j] == 'E')
            {
                ex = i, ey = j;
            }
        }
    }
    auto isValid = [&](int x, int y) -> bool
    {
        if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y] || v[x][y] == 'T') return false;

        return true;
    };
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector<vector<int>> dist(n, vector<int>(n, 0));
    auto f = [&](int x, int y) -> void
    {
        dist[x][y] = 0; vis[x][y] = true; queue<pair<int, int>> q; q.push({x, y});
        while(!q.empty())
        {
            int fx = q.front().ff;
            int fy = q.front().ss;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = fx + dx[i], ty = fy + dy[i];
                if(isValid(tx, ty))
                {
                    q.push({tx, ty});
                    vis[tx][ty] = true;
                    dist[tx][ty] = 1 + dist[fx][fy];
                }
            }
        }
    };
    f(srcx, srcy);
    cout << dist[ex][ey];
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
