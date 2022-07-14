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
    int a, b, k; cin >> a >> b >> k;
    string s = string(a + b, '0');
    string t = string(a + b, '0');
    int n = a + b;
    int i = n - 1, j = n - 1;
    --b;
    s[0] = t[0] = '1';
    if(k) {
        if(a == 0) {
            cout << "NO"; return 0;
        }
        s[i--] = '0';
        t[j--] = '1';
        --k;
        if(b == 0) {
            cout << "NO"; return 0;
        }
        --b, --a;
        while(k >= 0) {
            if(b && k) {
                s[i--] = t[j--] = '1';
                --b;
            }
            else if(a && k) {
                s[i--] = t[j--] = '0';
                --a;
            }
            else if(k == 0) {
                if(i == 0) {
                    cout << "NO"; return 0;
                }
                s[i--] = '1';
                t[j--] = '0';
                break;
            }
            else break;
            --k;
        }
        if(k > 0) {
            cout << "NO"; return 0;
        }
    }
    while(i > 0) {
        if(b) {
            s[i--] = t[j--] = '1'; --b;
        }
        else {
            s[i--] = t[j--] = '0'; --a;
        }
    }
    cout << "YES\n";
    cout << s << '\n' << t;
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
