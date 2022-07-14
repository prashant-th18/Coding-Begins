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
    vector<vector<int>> v(n, vector<int>(m, 0));
    set<pair<int, int>> st;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
        vector<int> temp = v[i];
        sort(temp.begin(), temp.end());
        vector<int> ind;
        for(int j = 0; j < m; ++j) {
            if(v[i][j] != temp[j]) ind.push_back(j);
        }
        if(sz(ind) > 2) {
            flag = true;
        }
        else if(sz(ind) == 2) {
            st.insert(pair(ind[0], ind[1]));
        }
    }
    if(flag) cout << -1;
    else {
        if(sz(st) > 1) {
            cout << -1;
        }
        else if(sz(st) == 1) {
            auto p = *st.begin();
            int a = p.ff, b = p.ss;
            for(int i = 0; i < n && !flag; ++i) {
                swap(v[i][a], v[i][b]);
                if(!is_sorted(all(v[i]))) {
                    flag = true;
                }
            }
            if(flag) cout << -1;
            else cout << a + 1 << ' ' << b + 1;
        }
        else {
            cout << "1 1";
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
