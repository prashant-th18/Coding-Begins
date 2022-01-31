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
#define long long int;
// *-> KISS*
int32_t solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<array<ll, 4>> v(n + 1); // U-R-D-L
    auto fun = [&](int index, int c, int add = 0) -> void
    {
          v[index][c] = v[index - 1][c] + add;
    };
    for (int i = 0; i < n; i++) {
        if(s[i] == 'U')
        {
            fun(i + 1, 0, 1);
        }
        else fun(i + 1, 0, 0);
        if(s[i] == 'R') fun(i + 1, 1, 1);
        else fun(i + 1, 1, 0);
        if(s[i] == 'D') fun(i + 1, 2, 1);
        else fun(i + 1, 2, 0);
        if(s[i] == 'L') fun(i + 1, 3, 1);
        else fun(i + 1, 3, 0);
    }
    for(int i = 0; i < n; ++i)
    {
        int px = 0, py = 0;
        int x = v[i + 1][1] - v[i + 1][3], y = v[i + 1][0] - v[i + 1][2];
        for(int j = 0; j < n; ++j)
        {
            if(s[j] == 'U')
            {
                if(px != x || (py + 1) != y) ++py;
            }
            else if(s[j] == 'R')
            {
                if((px + 1) != x || py != y) ++px;
            }
            else if(s[j] == 'D')
            {
                if(px != x || (py - 1) != y) --py;
            }
            else
            {
                if((px - 1) != x || py != y) --px;
            }
        }
        if(px == 0 && py == 0)
        {
            cout << x << ' ' << y; return 0;
        }
    }
    cout << 0 << ' ' << 0;
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
