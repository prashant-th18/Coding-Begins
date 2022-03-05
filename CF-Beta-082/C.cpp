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
vector<ll> arr, price;
vector<vector<ll>> dp;
ll f(ll index, ll sum)
{
    if(index == 0)
    {
        return dp[index][sum] = price[index] * (sum / arr[index]);
    }
    if(dp[index][sum] != -1)
    {
        return dp[index][sum];
    }
    // Either take this one, or leave it
    ll leave_it = f(index - 1, sum);
    ll take_it = ((sum >= arr[index]) ? (price[index] + f(index - 1, sum - arr[index])) : (leave_it));
    return dp[index][sum] = max(leave_it, take_it);
}
// *-> KISS*
int solve() {
    ll n, m, c, d; cin >> n >> m >> c >> d;
    price.push_back(d);
    arr.push_back(c);
    for (int i = 0; i < m; i++) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        for(int j = 0; j < A / B; ++j)
        {
            arr.push_back(C);
            price.push_back(D);
        }
    }
    dp.assign(sz(arr), vector<ll>(n + 1, -1));
    cout << f(sz(arr) - 1, n);
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
