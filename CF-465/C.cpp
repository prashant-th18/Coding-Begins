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
    auto check = [&](ld d1, ld d2) -> bool
    {
        if(abs(d1 - d2) <= 1e-9) return true;
        else return false;
    };
    ld r, x1, y1, x2, y2; cin >> r >> x1 >> y1 >> x2 >> y2;
    ld dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if(dis > r * r)
    {
        cout << x1 << ' ' << y1 << ' ' << r;
    }
    else if(check(dis, r * r))
    {
        cout << x1 << ' ' << y1 << ' ' << r;
    }
    else
    {
        ld rad = (r + sqrtl(dis)) / 2;
        if(x1 == x2)
        {
            if(y2 < y1)
            cout << x1 << ' ' << y2 + rad << ' ' << rad;
            else
            {
                cout << x1 << ' ' << y2 - rad << ' ' << rad;
            }
        }
        else
        {
            ld slope = (y1 - y2) / (x1 - x2);
            ld newx = x2, newy = y2, nn = rad * sqrtl(1 / (1 + slope * slope));
            if(x2 < x1)
            {
                newx += nn;
                newy += slope * nn; 
                cout << newx << ' ' << newy << ' ' << rad;
            }
            else {
                newx -= nn;
                newy -= slope * nn;
                cout << newx << ' ' << newy << ' ' << rad;
            }
        }
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
}
// -> Keep It Simple Stupid!
