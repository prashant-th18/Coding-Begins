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
    ll n, a, b; cin >> n >> a >> b;
    // ax + by == n
    ll x = -1, y = -1;
    for(ll i = 0; i < n; ++i)
    {
        // x = (n - b*i) / a
        if((n - b * i) % a == 0)
        {
            y = i, x = (n - b * i) / a; break;
        }
    }
    if(x < 0 || y < 0 || a*x + b*y != n)
    {
        cout << -1;
        return 0;
    }
    vector<ll> perm(2*n, 0);
    ll con = 0;
    for (int i = 0; i < x; i++) {
        for(ll j = a; j >= 1; --j)
        {
            ll what = con + (j + 1) % a;
            if(what == con) what += a;
            perm[what] = con + j;
        }
        con += a;
    }
    for (int i = 0; i < y; i++) {
            for(ll j = b; j >= 1; --j)
            {
                ll what = con + (j + 1) % b;
                if(what == con) what += b;
                perm[what] = con + j;
            }
            con += b;
    }
    for(int i = 1; i <= n; ++i) cout << perm[i] << ' ';
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
