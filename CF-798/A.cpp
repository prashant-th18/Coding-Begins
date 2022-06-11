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
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    int i = 0, j = 0, cnt = 0, flag = ((a[i] < b[j]) ? (0) : (1));
    string res = "";
    while(i < n && j < m) {
        if(flag == 0) {
            res += a[i++];
            ++cnt;
        }
        else {
            res += b[j++];
            ++cnt;
        }
        if(cnt == k) {
            flag = 1 - flag; cnt = 0;
        }
        else {
            if(i == n || j == m) break;
            else {
                if(flag == 0) {
                    if(a[i] < b[j]) {}
                    else cnt = 0, flag = 1 - flag;
                }
                else {
                    if(a[i] < b[j]) cnt = 0, flag = 0;
                }
            }
        }
    }
    cout << res;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET;
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
