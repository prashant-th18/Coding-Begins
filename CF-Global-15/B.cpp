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
    int n; cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(5);
        for (int j = 0; j < 5; j++) {
            cin >> temp[j];
        }
        v[i] = temp;
    }
    vector<int> players(n);
    iota(all(players), 0);
    auto f = [&](int a, int b) -> bool
    {
          int pa, pb; pa = pb = {};
          for(int j = 0; j < 5; ++j)
          {
              if(v[a][j] < v[b][j]) ++pa;
              else if(v[b][j] < v[a][j]) ++pb;
          }
          return pa > pb;
    };
    sort(players.begin(), players.end(), f);
    auto check = [&]()
    {
        int ind = players[0];
        int cnt = 0;
        for(int i = 1; i < n; ++i)
        {
            int c {};
            for(int j = 0; j < 5; ++j)
            {
                if(v[ind][j] < v[players[i]][j]) ++c;
            }
            cnt += (c >= 3);
        }
        return cnt == n - 1;
    };
    if(n == 1) cout << 1;
    else
    {
        if(check())
        cout << players[0] + 1;
        else 
        cout << -1;
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
