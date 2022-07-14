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
    string a, b; cin >> a >> b;
    if(sz(a) > sz(b)) {
        cout << "No"; return 0;
    }
    else {
        auto fun = [&](string s) {
            vector<pair<char, int>> v;
            int c = 0;
            for(int i = 0; i < sz(s); ++i) {
                if(i == 0) ++c;
                else {
                    if(s[i] == s[i - 1]) ++c;
                    else {
                        v.push_back(pair(s[i - 1], c));
                        c = 1;
                    }
                }
            }
            v.push_back(pair(s[sz(s) - 1], c));
            return v;
        };
        auto v1 = fun(a), v2 = fun(b);
        int n = sz(v1), m = sz(v2);
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(v1[i].ff != v2[j].ff) {
                cout << "No"; return 0;
            }
            else {
                if(v1[i].ss > v2[j].ss || (v2[j].ss > 1 && v1[i].ss == 1)) {
                    cout << "No"; return 0;
                }
                else ++i, ++j;
            }
        }
        if(i == n && j == m) cout << "Yes";
        else cout << "No";
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
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
