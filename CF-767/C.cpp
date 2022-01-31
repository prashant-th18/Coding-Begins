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
    unordered_map<int, deque<int>> mp;
    for (int i = 0; i < n; i++) {
        int tt; cin >> tt;
        mp[tt].push_back(i + 1);
    }
    int at_top = 0;
    ll elem = n;
    vector<int> ans;
    while(elem != 0)
    {
        ll s = 0;
        if(sz(mp[0]) == 0)
        {
            for(int i = 0; i < elem; ++i) ans.push_back(0);
            elem = 0; continue;
        }
        else
        {
            int my_top = at_top + 1;
            while(sz(mp[s]) != 0)
            {
                if(mp[s][0] > at_top)
                {
                    my_top = max(mp[s][0], my_top);
                    mp[s].pop_front();
                    ++s;
                }
                else
                {
                    while(sz(mp[s]) != 0 && mp[s][0] <= at_top)
                    {
                        mp[s].pop_front();
                    }
                }
            }
            ans.push_back(s);
            elem = n - my_top;
            at_top = max(at_top, my_top); ////////////
        }
    }
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << ' ';
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
