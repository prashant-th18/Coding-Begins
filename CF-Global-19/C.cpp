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
    ll n; cin >> n;
    vector<ll> v(n);
    priority_queue<ll> odd, even;
    for (int i = 0; i < n; ++i) {
        ll val; cin >> val;
        if(1 <= i && i <= n - 2) {
        if(val & 1)
        {
            odd.push(val);
        }
        else even.push(val);
        }
    }
    ll ans = 0;
    while(!odd.empty() || !even.empty())
    {
        if(odd.empty())
        {
           while(!even.empty())
           {
               ans += (even.top() >> 1);
               even.pop();
           }
        }
        while(!odd.empty() && !even.empty())
        {
                ll tt1 = even.top(); even.pop();
                ll tt2 = odd.top(); odd.pop();
                ++ans;
                tt1 -= 2;
                tt2++;
                if(tt1) even.push(tt1);
                even.push(tt2);
        }
        if(odd.empty() == false && even.empty() == true)
        {
            ll tt = odd.top(); odd.pop();
            if(tt == 1 || sz(odd) == 0)
            {
                cout << -1; return 0;
            }
            else
            {
                tt -= 2;
                ++ans;
                ll t1 = odd.top(); odd.pop();
                even.push(t1 + 1);
                odd.push(tt);
            }
        }
    }
    cout << ans;
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
