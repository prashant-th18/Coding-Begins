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
vector<string> two, three;
// *-> KISS*
int solve() {
    int n; cin >> n;
    string s = to_string(n);
    auto diff = [&](string a, string b) -> int
    {
        int c = 0;
        for(int i = 0; i < sz(a); ++i)
        {
            if(a[i] != b[i]) ++c;
        }
        return c;
    };
    string number;
    if(sz(s) == 2)
    {
        int maxx = 1e9;
        for(int i = 0; i < sz(two); ++i)
        {
            int temp = diff(s, two[i]);
            if(temp < maxx)
            {
                number = two[i];
                maxx = temp;
            }
        }
        cout << number;
    }
    else
    {
        int maxx = 1e9;
        for(int i = 0; i < sz(three); ++i)
        {
            int temp = diff(s, three[i]);
            if(temp < maxx)
            {
                maxx = temp;
                number = three[i];
            }
        }
        cout << number;
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    for(int i = 14; i < 1000; i += 7)
    {
        if(i < 100)
        two.push_back(to_string(i));
        else
        three.push_back(to_string(i));
    }
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
