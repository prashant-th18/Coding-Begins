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

string make(int i)
{
    string res = "";
    while(i)
    {
        if(i & 1) res += "1";
        else res += "0";
        i >>= 1;
    }
    reverse(all(res));
    return res;
}
int bin(string s)
{
    int i = sz(s) - 1;
    int res = 0;
    while(i >= 0)
    {
        res += (1 << (sz(s) - 1 - i)) * (s[i] - '0');
        --i;
    }
    return res;
}
// *-> KISS*
int solve() {
    // Case Work
    vector<string> v;
    for(int i = 1; i <= (1 << 5) - 1; ++i)
    {
        v.push_back(make(i));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < sz(v); ++i)
    {
        cout << __builtin_popcount(bin(v[i])) << ' ';
    }
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
