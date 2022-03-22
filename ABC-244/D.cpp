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
    string a = string(3, '.');
    cin >> a[0] >> a[1] >> a[2];
    string b = string(3, '.');
    cin >> b[0] >> b[1] >> b[2];
    auto cc = [&](char ch)
    {
        return count(all(a), ch) == count(all(b), ch);  
    };
    if(!(cc('R') && cc('G') && cc('B')))
    {
        cout << "No"; return 0;
    }
    if(a == b)
    {
        cout << "Yes";
    }
    else
    {
        vector<int> v;
        for (int i = 0; i < 3; i++) {
            if(a[i] != b[i]) v.push_back(i);
        }
        if(sz(v) == 3)
        {
            cout << "Yes";
        }
        else if(sz(v) == 2)
        {
            int which = 1;
            for (int i = 1; i < 4; i++) {
                if(find(all(v), i) == v.end())
                {
                    which = i; break;
                }
            }
            if(b[v[0]] == b[which] || b[v[1]] == b[which])
            {
                cout << "Yes";
            }
            else cout << "No";
        }
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
