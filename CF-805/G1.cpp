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

int n;
vector<vector<int>> v;
vector<int> d;
map<int, int> pres;
void depth(int node, int de = 0, int p = -1) {
    d[node] = de;
    for(const auto& val : v[node]) {
        if(val != p) {
            depth(val, de + 1, node);
        }
    }
}
// 0 -> Nothing
// 1 -> Okay good and present
// 2 -> Not good
int dfs(int node, int p = -1) {
    int t = (pres[node]), c = 0;
    for(const auto& val : v[node]) {
        if(val == p) continue;
        int x = dfs(val, node);
        if(x == 2) {
            // Gye
            return 2;
        }
        else if(x == 1) {
            ++c;
            t = 1;
        }
    }
    if(c > 1) {
        t = 2;
    }
    return t;
}
// Paas parent
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n + 1, vector<int>());
    d.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth(1);
    int q; cin >> q;
    while(q--) {
        int k; cin >> k;
        vector<int> temp(k, 0);
        pres.clear();
        for (int i = 0; i < k; i++) {
            cin >> temp[i];
            pres[temp[i]] = true;
        }
        sort(temp.begin(), temp.end(), [&](int a, int b) {
           return d[a] > d[b]; 
        });
        int x = dfs(temp[0]);
        if(x == 2) cout << "No\n";
        else cout << "Yes\n";
    }
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
