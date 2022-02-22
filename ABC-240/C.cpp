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
int n;
vector<int> a, b;
vector<vector<int>> dp;
int f(int x, int index)
{
    if(x == 0 && index == -1) return 1;
    
    if(index < 0 || x < 0) return -1;

    if(dp[x][index] != 0) return dp[x][index];

    int flag = f(x - a[index], index - 1);
    if(flag == 1) 
        return dp[x][index] = 1;

    flag = f(x - b[index], index - 1);

    if(flag == 1) 
        return dp[x][index] = 1;
    else 
        return dp[x][index] = -1;
}
// *-> KISS*
int solve() {
    cin >> n;
    int x; cin >> x;
    a.assign(n, 0); b.assign(n, 0);
    dp.assign(x + 1, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << ((f(x, n - 1) == 1) ? ("Yes") : ("No"));
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
