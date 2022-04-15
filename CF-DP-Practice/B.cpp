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
const int MOD = 1000000007;
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

string s;
int check(int index)
{
    if(s[index] == 'w') return -1;
    else if(s[index] == '"') return 0;
    else return 1;
}
// *-> KISS*
int solve() {
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    int n; cin >> n;
    cin >> s;
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        if(dp[i] == -1) continue;
        if(i + 1 < n && check(i + 1) >= 0)
        {
            dp[i + 1] = max(dp[i + 1], dp[i] + (s[i + 1] == '"'));
        }
        if(i + 3 < n && check(i + 3) >= 0)
        {
            dp[i + 3] = max(dp[i + 3], dp[i] + (s[i + 3] == '"'));
        }
        if(i + 5 < n && check(i + 5) >= 0)
        {
            dp[i + 5] = max(dp[i + 5], dp[i] + (s[i + 5] == '"'));
        }
    }
    cout << dp[n - 1];
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
