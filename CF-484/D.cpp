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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]] = i + 1;
    }
    set<int> bpoints; // breakpoints
    multiset<int> groups;
    bpoints.insert(0); bpoints.insert(n + 1);
    groups.insert(n);
    int maxx = 1, k = v[n - 1] + 1;
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < n; ++i) {
        auto it = bpoints.lower_bound(mp[v[i]]);
        auto it_ahead = it--;
        groups.erase(groups.lower_bound((*it_ahead) - (*it) - 1));
        int one = (*it_ahead) - mp[v[i]] - 1;
        int sec = mp[v[i]] - (*it) - 1;
        if(one != 0) groups.insert(one);
        if(sec != 0) groups.insert(sec);
        bpoints.insert(mp[v[i]]);
        if(sz(groups) != 0 && (*groups.begin()) == (*groups.rbegin())) {
            if(sz(groups) >= maxx) {
                maxx = sz(groups);
                if(i + 1 <= n - 1) k = v[i + 1] + 1;
                else k = v[i];
            }
        }
    }
    cout << k;
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
