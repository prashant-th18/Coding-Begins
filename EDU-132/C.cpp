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

bool check(string s) {
    int bal = 0;
    for(int i = 0; i < sz(s); ++i) {
        if(s[i] == '(') ++bal;
        else {
            --bal;
        }
        if(bal < 0) return false;
    }
    return bal == 0;
}
// *-> KISS*
int solve() {
    string s; cin >> s;
    int n = sz(s);
    int l = n / 2, r = n / 2;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '(') --l;
        else if(s[i] == ')') --r;
    }
    int p1 = -1, p2 = -1;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '?') {
            if(l > 0) {
                p1 = i;
                --l;
                s[i] = '(';
            }
            else {
                if(p2 == -1) p2 = i;
                --r;
                s[i] = ')';
            }
        }
    }
    if(p1 != -1 && p2 != -1) {
        swap(s[p1], s[p2]);
        if(!check(s)) cout << "Yes";
        else cout << "No";
    }
    else cout << "Yes";
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
