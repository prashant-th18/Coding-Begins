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
    ll hc, dc, hm, dm; cin >> hc >> dc >> hm >> dm;
    ll k, w, a; cin >> k >> w >> a;
    // monster gets killed in -> (hm + dc - 1) / dc
    // I get killed in -> (hc + dm - 1) / dm
    for(ll i = 0; i <= k; ++i)
    {
        // i -> used for armor upgrade
        // (k - i) -> used for weapon upgrade
        ll attack = dc + i * w;
        ll def = hc + (k - i) * a;
        ll me_ded = (def + dm - 1) / dm;
        ll mon_ded = (hm + attack - 1) / attack;
        if(mon_ded <= me_ded)
        {
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
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
