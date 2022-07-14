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
    int n; cin >> n;
    vector<vector<array<int, 2>>> v(n);
    map<int, int> tot, maxx;
    map<int, vector<int>> keep;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        vector<array<int, 2>> temp(m);
        for (int j = 0; j < m; j++) {
            int a, b; cin >> a >> b;
            temp[j] = {a, b};
            tot[a] += b;
            maxx[a] = max(maxx[a], b);
            keep[a].push_back(b);
        }
        v[i] = temp;
    }
    for(auto& val : keep) {
        sort(val.ss.begin(), val.ss.end(), greater<int>());
    }
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++) {
        int m = sz(v[i]);
        // Replace with 1
        vector<pair<int, int>> temp;
        for(int j = 0; j < m; ++j) {
            if(maxx[v[i][j][0]] == v[i][j][1]) {
                if(sz(keep[v[i][j][0]]) == 1) {
                    temp.push_back(pair(v[i][j][0], 0));
                }
                else {
                    if(keep[v[i][j][0]][1] != v[i][j][1]) temp.push_back(pair(v[i][j][0], keep[v[i][j][0]][1]));
                }
            }
        }
        st.insert(temp);
    }
    cout << sz(st);
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
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
