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

// *-> KISS*
int solve() {
    int n; cin >> n;
    n *= 2;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) { 
        cin >> v[i]; 
    }
    map<int, int> mp;
    mp[0] = n;
    int c = 0;
    for(int i = n - 1; i >= (n >> 1); --i)
    {
        c += ((v[i] == 1) ? (-1) : (1));
        mp[c] = i;
    }
    c = 0;
    int ans = min(n, mp[0]); // n / 2 + (mp[0] - n / 2)
    for(int i = 0; i < n / 2; ++i)
    {
        c += ((v[i] == 1) ? (-1) : (1));
        if(mp.count(-c))
        {
            // n / 2 - i - 1
            // mp[-c] - n / 2
            ans = min(ans, mp[-c] - i - 1);
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
