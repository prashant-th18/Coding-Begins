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
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    double x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    double x5, y5, x6, y6; cin >> x5 >> y5 >> x6 >> y6;
    auto c = [&](double& X1, double& Y1, double& X2, double& Y2) -> void    
    {
        X1 = max(x1, X1);
        Y1 = max(y1, Y1);

        X2 = min(x2, X2);
        Y2 = min(y2, Y2);
    };
    c(x3, y3, x4, y4);
    c(x5, y5, x6, y6);
    auto check = [&](double x, double y) -> bool
    {
        if((x3 <= x && x <= x4 && y3 <= y && y <= y4) || (x5 <= x && x <= x6 && y5 <= y && y <= y6))
        {
            return false;
        }
        else if((x1 <= x && x <= x2 && y1 <= y && y <= y2))
        return true;
        else
            return false;
    };
    if(check(x3 - 0.5, y3) || check(x3 - 0.5, y4) || check(x3, y4 + 0.5) || check(x4, y4 + 0.5) || check(x4 + 0.5, y4) || check(x4, y3 + 0.5) || check(x4, y3 - 0.5) || check(x3, y3 - 0.5) || check(x5 - 0.5, y5) || check(x5 - 0.5, y6) || check(x5, y6 + 0.5) || check(x6, y6 + 0.5) || check(x6 + 0.5, y6) || check(x6, y5 + 0.5) || check(x6, y5 - 0.5) || check(x5, y5 - 0.5) || check(x1 + 0.5, y1) || check(x1 + 0.5, y2) || check(x2 - 0.5, y2) || check(x2 - 0.5, y1))
    cout << "YES\n";
    else cout << "NO\n";
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
