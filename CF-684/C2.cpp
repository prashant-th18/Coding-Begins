#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> ans;
    auto check = [&](int i, int j) -> bool {
        if(i >= 0 && i < n && j >= 0 && j < m) return true;
        return false;
    };
    int dx[] = {0, 0, 1, 1};
    int dy[] = {0, 1, 0, 1};
    for (int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; ++j) {
            if(v[i][j] == 0) continue;
            vector<pair<int, int>> temp, other;
            for(int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if(check(ni, nj)) {
                    if(v[ni][nj] == '1')
                        temp.push_back({ni, nj});
                    else 
                        other.push_back({ni, nj});
                }
            }
            vector<int> tt;
            if(sz(temp) >= 3) {
                for(int k = 0; k < 3; ++k) {
                    tt.push_back(temp[k].ff);
                    tt.push_back(temp[k].ss);
                }
                ans.push_back(tt);
            }
            else {
                for (int k = 0; k < 1; k++) {
                    tt.push_back(temp[k].ff);
                    tt.push_back(temp[k].ss);
                }
                if(sz(temp) == 2) {
                    tt.push_back(temp[1].ff); tt.push_back(temp[1].ss);
                    tt.push_back(other[0].ff); tt.push_back(other[0].ss);
                    v[other[0].ff][other[0].ss] = '1';
                }
                else {
                    for (int k = 0; k < 2; k++) {
                        v[other[k].ff][other[k].ss] = '1';
                        tt.push_back(other[k].ff);
                        tt.push_back(other[k].ss);
                    }
                }
                ans.push_back(tt);
            }
        }
    }
    for(int j = 0; j < m - 1; ++j) {
        if(v[n - 1][j] == '1') {
            
        }
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
    int TET = 1;
    if(test) cin >> TET;
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
