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
    int n; cin >> n;
    string s; cin >> s;
    set<int> odd, even;
    for (int i = 0; i < n; i++) {
        if(s[i] == '0') even.insert(i);
        else odd.insert(i);
    }
    int c = 0;
    vector<int> ind(n);
    while(sz(even) + sz(odd) != 0)
    {
        if(sz(odd) != 0 && sz(even) != 0)
        {
            int i = 0, value = min(*odd.begin(), *even.begin());
            if(*odd.begin() < *even.begin()) i = 0, odd.erase(odd.begin());
            else i = 1, even.erase(even.begin());
            ind[value] = c;
            while(1)
            {
                if(i % 2 == 0)
                {
                    auto it = even.lower_bound(value);
                    if(it == even.end()) break;
                    else value = *it, even.erase(it);
                }
                else
                {
                    auto it = odd.lower_bound(value);
                    if(it == odd.end()) break;
                    else value = *it, odd.erase(it);
                }
                ind[value] = c;
                ++i;
            }
            ++c;
        }
        else
        {
            while(sz(odd) != 0) ind[*odd.begin()] = c++, odd.erase(odd.begin());
            while(sz(even) != 0) ind[*even.begin()] = c++, even.erase(even.begin());
            break;
        }
    }
    cout << c << '\n';
    for(auto val : ind)
    {
        cout << val + 1 << ' ';
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
