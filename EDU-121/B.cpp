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
#define MOD 1000000007
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
    string s; cin >> s;
    int last = -1;
    for(int i = 0; i < sz(s) - 1; ++i)
    {
        int dig1 = s[i] - '0';
        int dig2 = s[i + 1] - '0';
        if(dig1 + dig2 >= 10)
        {
            last = i;
        }
    }
    if(last != -1)
    {
        string res = "";
        res += s.substr(0, last);
        int sum = (s[last] - '0') + (s[last + 1] - '0');
        res += to_string(sum);
        res += s.substr(last + 2);
        cout << res;
    }
    else
    {
        string res = "";
        int sum = (s[0] - '0') + (s[1] - '0');
        res += to_string(sum);
        res += s.substr(2);
        cout << res;
    }
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
}
// -> Keep It Simple Stupid!
