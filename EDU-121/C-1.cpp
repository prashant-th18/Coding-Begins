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
    vector<ll> seconds(n);
    for (int i = 0; i < n; i++) {
        cin >> seconds[i];
    }
    vector<ll> health(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    ll ans = 0;
    vector<bool> mp(n + 1, false);
    for(int i = n - 2; i >= 0; --i)
    {
        ll t = seconds[i + 1] - seconds[i];
        t = health[i + 1] - t;
        if(t >= 1)
        {
            mp[i] = true;
        }
        health[i] = max(health[i], t);
    }
    bool connect = false;
    for(int i = 0; i < n; ++i)
    {
        if(!connect)
        {
            ans += (health[i] * (health[i] + 1)) / 2;
        }
        else
        {
            ll temp = health[i - 1] + (seconds[i] - seconds[i - 1]);
            ans += (temp * (temp + 1) / 2 - (health[i - 1] * (health[i - 1] + 1) / 2));
            health[i] = max(health[i], temp);
        }
        if(mp[i])
        {
            connect = true;
        }
        else connect = false;
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
}
// -> Keep It Simple Stupid!

