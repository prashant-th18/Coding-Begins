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
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m, '0'));
    auto ans = v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> fans;
    for(int j = m - 1; j >= 1; --j)
    {
        for(int i = n - 1; i >= 0; --i)
        {
            // need 1?
            if(v[i][j] == '1')
            {
                vector<int> temp;
                temp.push_back(i + 1);
                temp.push_back(j);
                temp.push_back(i + 1); temp.push_back(j + 1);
                fans.push_back(temp);
                ans[i][j - 1] = '0'; ans[i][j] = '1';
            }
        }
    }
    for(int i = n - 1; i >= 1; --i)
    {
        if(v[i][0] == '0') continue;
        vector<int> temp;
        temp.push_back(i); temp.push_back(1); temp.push_back(i + 1); temp.push_back(1);
        fans.push_back(temp);
        ans[i][0] = '1';
    }
    if(ans == v)
    {
        cout << sz(fans) << '\n';
        for(int i = 0; i < sz(fans); ++i)
        {
            for(auto val : fans[i]) cout << val << ' ';
            cout << '\n';
        }
    }
    else cout << -1;
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
