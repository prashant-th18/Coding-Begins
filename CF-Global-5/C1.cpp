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
    vector<array<int, 4>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][3] = i + 1;
    }
    auto f = [&](array<int, 4> a, array<int, 4> b)
    {
        if(a[0] != b[0])
        {
            return a[0] < b[0];
        }
        if(a[1] != b[1])
        {
            return a[1] < b[1];
        }
        return a[2] < b[2];
    };
    sort(all(v), f);
    vector<bool> vis(n + 1, false);
    for(int i = 0; i < sz(v) - 1; i++)
    {
        ll x1 = min(v[i][0], v[i + 1][0]), x2 = max(v[i][0], v[i + 1][0]);
        ll y1 = min(v[i][1], v[i + 1][1]), y2 = max(v[i][1], v[i + 1][1]);
        ll z1 = min(v[i][2], v[i + 1][2]), z2 = max(v[i][2], v[i + 1][2]);
        bool flag = false;
        for (int j = 0; j < sz(v); j++) {
            if(j == i || j == i + 1) continue;
            if((x1 <= v[j][0] && v[j][0] <= x2) && (y1 <= v[j][1] && v[j][1] <= y2) && (z1 <= v[j][2] && v[j][2] <= z2))
                    {
                        flag = true; break;
                    }
            else
            {
                assert(true);
            }
        }
        if(!flag)
        {
            cout << v[i][3] << ' ' << v[i + 1][3] << '\n';
            auto it = v.begin() + i;
            v.erase(it); it = v.begin() + i;
            v.erase(it);
            i = -1;
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
