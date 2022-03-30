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
    int n, d; cin >> n >> d;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) { 
        cin >> v[i]; 
    }
    vector<bool> vis(n, false);
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i)
    {
        if(vis[i]) continue;
        int ind = i;
        vector<int> temp;
        while(!vis[ind])
        {
            vis[ind] = true;
            temp.push_back(v[ind]);
            ind = (ind + d) % n;
        }
        if(count(all(temp), 1) == sz(temp))
        {
            cout << -1; return 0;
        }
        ans.push_back(temp);
    }
    int steps = 0;
    for (int i = 0; i < sz(ans); i++) {
        vector<int>& temp = ans[i];
        int ind = find(all(temp), 0) - begin(temp);
        auto dec = [&]() -> void
        {
            ind = (ind - 1 + sz(temp)) % sz(temp);  
        };
        int cnt = 0, pre = 0;
        dec();
        while(cnt < sz(temp))
        {
            if(temp[ind] == 0)
            {
                steps = max(steps, pre);
                pre = 0;
            }
            else
            {
                ++pre;
            }
            dec();
            ++cnt;
        }
        steps = max(steps, pre);
    }
    cout << steps;
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
