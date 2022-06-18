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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, int> mp;
    vector<int> prefix(n, 0), suffix(n, 0);
    prefix[0] = suffix[n - 1] = 1;
    mp[1] = 2;
    for(int i = 1; i < n; ++i) 
    {
        prefix[i] = 1 + ((v[i - 1] < v[i]) ? (prefix[i - 1]) : (0));
        mp[prefix[i]]++;
    }
    for(int i = n - 2; i >= 0; --i) {
        suffix[i] = 1 + ((v[i] > v[i + 1]) ? (suffix[i + 1]) : (0));
        mp[suffix[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        int l = prefix[i], r = suffix[i];
        if(l == r && l > 1 && mp.rbegin() -> first == l && l % 2 == 1 && mp[l] == 2) ++cnt;
    }
    cout << cnt;
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
