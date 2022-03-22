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
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    auto abso = [&](vector<ll>& temp, ll num) -> ll
    {
        ll t = 0;
        for (int i = 0; i < sz(temp); i++) {
            t += abs(num - temp[i]);
        }
        return t;
    };
    auto fun = [&](vector<ll>& temp) -> ll
    {
        sort(temp.begin(), temp.end());
        return abso(temp, temp[sz(temp) / 2]);
    };
    vector<vector<ll>> ans;
    int i = 0, j = n - 1;
    while(i <= j)
    {
        if(i < j)
        {
            vector<ll> temp;
            int l = 0, r = m - 1;
            while(l <= r)
            {
                if(l == r)
                {
                    temp.push_back(v[i][l]);
                    temp.push_back(v[j][r]);
                    ++l, --r;
                }
                else
                {
                    temp.push_back(v[i][l]); temp.push_back(v[j][r]);
                    temp.push_back(v[i][r]); temp.push_back(v[j][l]);
                    ++l, --r;
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        else
        {
            vector<ll> temp;
            int l = 0, r = m - 1;
            while(l <= r)
            {
                if(l == r) temp.push_back(v[i][l++]);
                else
                {
                    temp.push_back(v[i][l++]);
                    temp.push_back(v[i][r--]);
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        ++i, --j;
    }
    ll a = 0;
    for (int ii = 0; ii < sz(ans); ii++) {
        a += fun(ans[ii]);
    }
    cout << a;
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
