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
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// use -> auto gcd = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> dp1(n, vector<ll>(m, -1)), dp2(n, vector<ll>(m, -1));
    auto f1 = y_combinator([&](auto f, int i, int j) -> ll // 1, 1  --->  n, m
    {
        // Either I can go Right or Down
        ll maxx1 = 0, maxx2 = 0;
        if(i + 1 <= n - 1) // down
        {
            if(dp1[i + 1][j] != -1)
            {
                maxx1 = dp1[i + 1][j];
            }
            else maxx1 = dp1[i + 1][j] = f(i + 1, j);
        }
        if(j + 1 <= m - 1)
        {
            if(dp1[i][j + 1] != -1)
            {
                maxx2 = dp1[i][j + 1];
            }
            else
            {
                maxx2 = dp1[i][j + 1] = f(i, j + 1);
            }
        }
        maxx1 += v[i][j];
        maxx2 += v[i][j];
        dp1[i][j] = max(maxx1, maxx2);
        return dp1[i][j];
    });
    auto f2 = y_combinator([&](auto f, int i, int j) -> ll // 1, 1  --->  n, m
    {
          // Either I can go Right or Up
          ll maxx1 = 0, maxx2 = maxx1;
          if(i - 1 >= 0) // up
          {
              if(dp2[i - 1][j] != -1)
              {
                  maxx1 = dp2[i - 1][j];
              }
              else maxx1 = dp2[i - 1][j] = f(i - 1, j);
          }
          if(j + 1 <= m - 1)
          {
              if(dp2[i][j + 1] != -1)
              {
                  maxx2 = dp2[i][j + 1];
              }
              else
              {
                  maxx2 = dp2[i][j + 1] = f(i, j + 1);
              }
          }
          maxx1 += v[i][j];
          maxx2 += v[i][j];
          dp2[i][j] = max(maxx1, maxx2);
          return dp2[i][j];
    });
    f1(0, 0);
    f2(n - 1, 0);
    vector<vector<int>> grid1(n, vector<int>(m, 0));
    auto grid2 = grid1;
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        cout << i << ' ' << j << endl;
        grid1[i][j]++;
        if(i + 1 < n && j + 1 < m)
        {
            if(dp1[i][j + 1] > dp1[i + 1][j]) ++j;
            else ++i;
        }
        else if(i + 1 < n)
        {
            ++i;
        }
        else ++j;
    }
    cout << endl;
    i = n - 1, j = 0;
    while(i >= 0 && j < m)
    {
        cout << i << ' ' << j << endl;
        grid2[i][j]++;
        if(i - 1 >= 0 && j + 1 < m)
        {
            if(dp2[i - 1][j] > dp2[i][j + 1]) --i;
            else ++j;
        }
        else if(i - 1 >= 0)
        {
            --i;
        }
        else ++j;
    }
    ll mini = 1e9;
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            if(grid1[ii][jj] == grid2[ii][jj] && grid1[ii][jj] == 1) mini = min(mini, v[ii][jj]);
        }
    }
    cout << dp1[0][0] + dp2[n - 1][0] - 2 * mini;
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
