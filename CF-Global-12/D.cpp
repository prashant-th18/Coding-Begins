#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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
    map<int, int> occ;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ++occ[v[i]];
    }
    string res = string(n, '0');
    if(count(all(v), 1) != 0)  {
        int c = 1;
        res[n - c] = '1';
        int i = 0, j = n - 1;
        while(i < j) {
            if(v[i] == c) {
                res[n - c] = '1';
                if(--occ[v[i]] > 0) break;
                ++c;
                ++i;
            }
            else if(v[j] == c) {
                res[n - c] = '1';
                if(--occ[v[j]] > 0) break;
                ++c;
                --j;
            }
            else {
                if(occ[c]) res[n - c] = '1';
                break;
            }
        }
        sort(v.begin(), v.end());
        vector<int> temp(n, 0); iota(all(temp), 1);
        if(v == temp) res[0] = '1';
    }
    cout << res;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
    int TET = 1;
    if(test) cin >> TET;
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
