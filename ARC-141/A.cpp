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

ll first(ll i) {
    ll res = 1;
    for(int j = 0; j < i - 1; ++j) res *= 10;
    return res;
}
bool check(string& a, string& b) {
    if(sz(a) > sz(b)) return true;
    else if(sz(a) < sz(b)) return false;
    else return a > b;
}
// *-> KISS*
int solve() {
    string s; cin >> s;
    int n = s.size();
    string maybe = "";
    auto fun = [&]() -> void {
    for(int i = 1; i < n; ++i) {
        if(n % i == 0) {
            // i, n / i
            // i length ki string -> n / i times repeated
            // 1 (i - 1) 0's ..... 9 (i - 1) 9's
            int how = n / i;
            ll a = first(i);
            ll b = a * 10 - 1;
            while(a <= b) {
                ll mid = (a + b) >> 1;
                string create = to_string(mid);
                string res = "";
                for(int j = 0; j < how; ++j) {
                    res += create;
                }
                if(res <= s) {
                    if(check(res, maybe)) {
                        maybe = res;
                    }
                    a = mid + 1;
                }
                else {
                    b = mid - 1;
                }
            }
        }
    }
    };
    fun();
    ll num = stoll(s);
    num -= (num % (first(n)));
    --num;
    s = to_string(num);
    n = s.size();
    fun();
    cout << maybe;
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
