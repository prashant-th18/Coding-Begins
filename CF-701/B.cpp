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
    ll n, q, k; cin >> n >> q >> k;
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
    }
    vector<array<ll, 3>> dp(n);
    for (int i = 0; i < n; i++) {
        // 0 -> back
        // 1 -> back + front
        // 2 -> front
        if(i == 0)
        {
            dp[i][0] = k - 1;
            dp[i][2] = (((i + 1 < n) ? (v[i + 1] - 2) : (k - 1)));
        }
        else if(i == n - 1)
        {
            dp[i][2] = k - 1;
            dp[i][0] = (((i - 1 >= 0) ? (k - v[i - 1] - 1) : (k - 1)));
        }
        else
        {
            dp[i][0] = k - v[i - 1] - 1;
            dp[i][2] = v[i + 1] - 2;
            dp[i][1] = v[i + 1] - v[i - 1] - 2;
        }
    }
    vector<ll> prefix(n + 1);
    for(int i = 0; i < n; ++i)
    {
        prefix[i + 1] = prefix[i] + dp[i][1];
    }
    while(q--)
    {
        ll a, b; cin >> a >> b;
        if(a == b)
        {
            cout << k - 1 << '\n';
            continue;
        }
        --a;
        ll sum = prefix[b] - prefix[a];
        sum -= (dp[a][1] + dp[b - 1][1]);
        sum += (dp[a][2] + dp[b - 1][0]);
        cout << sum << '\n';
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
    return 0;
}
// -> Keep It Simple Stupid!
