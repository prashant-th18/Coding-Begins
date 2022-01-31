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
    auto binexp = [&](ll base, ll power) -> ll
    {
        ll res = 1;
        while(power)
        {
            if(power & 1) res *= base;
            base *= base;
            power >>= 1;
        }
        return res;
    };
    ll n; cin >> n;
    ll ans = 1, num = n, minn = 0;
    int cc = 0;
    while(num % 2 == 0)
    {
        num /= 2; ++cc;
    }
    if(cc > minn)
    {
        minn = cc; ans = 2;
    }
    for(ll i = 3; i * i <= n; i += 2)
    {
        int c = 0;
        while(num % i == 0) 
        {
            num /= i;
            ++c;
        }
        if(c != 0)
        {
            if(c > minn)
            {
                minn = c;
                ans = i;
            }
        }
    }
    if(num != 1)
    {
        if(1 > minn) minn = 1, ans = num;
    }
    cout << minn << '\n';
    for(int i = 0; i < minn - 1; ++i)
    {
        cout << ans << ' ';
    }
    n /= binexp(ans, minn - 1);
    cout << n;
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
