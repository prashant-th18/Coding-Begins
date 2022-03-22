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
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; ++i) { 
        cin >> a[i]; 
        if(mp.count(a[i]) == false) mp[a[i]] = i;
    }
    vector<int> b(n);
    for(int i = 0; i < n; ++i) { 
        cin >> b[i]; 
    }
    for(int i = n - 1; i >= 0; --i)
    {
        int diff = b[i] - a[i];
        int num = (diff > 0) ? (1) : (-1);
        if(diff > 0)
        {
            if(mp.count(num) && mp[num] < i) {}
            else
            {
                cout << "No"; return 0;
            }
        }
        else if(diff < 0)
        {
            if(mp.count(num) && mp[num] < i) {}
            else
            {
                cout << "No"; return 0;
            }
        }
    }
    cout << "Yes";
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
