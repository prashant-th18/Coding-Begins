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
    vector<pair<int, int>> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i + 1].ff >> v[i + 1].ss;
    }
    vector<bool> vis(n + 1, false);
    vector<int> ans; ans.push_back(1); vis[1] = true;
    int i = 0;
    auto check = [&](int num, int c) -> bool
    {
        if(v[num].ff == c || v[num].ss == c) return true;
        return false;
    };
    while(i <= n)
    {
        if(i == 0)
        {
            int one = v[ans[i]].ff, two = v[ans[i]].ss;
            if(check(one, two))
            {
                ans.push_back(one); ans.push_back(two);
            }
            else
            {
                ans.push_back(two); ans.push_back(one);
            }
            vis[one] = vis[two] = true;
            ++i;
        }
        else
        {
            if(!vis[v[ans[i]].ff])
            {
                vis[v[ans[i]].ff] = true; ans.push_back(v[ans[i]].ff);
            }
            else if(!vis[v[ans[i]].ss])
            {
                vis[v[ans[i]].ss] = true; ans.push_back(v[ans[i]].ss);
            }
            else break;
            ++i;
        }
    }
    for(const auto& val : ans) cout << val << ' ';
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
}
// -> Keep It Simple Stupid!
