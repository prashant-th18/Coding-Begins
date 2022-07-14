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
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    priority_queue<array<int, 3>> pq; // weight, node1, node2
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        pq.push({w, u, v});
    }
    ll sum = 0;
    while(!pq.empty()) {
        if(pq.top()[0] <= 0) break;
        else {
            array<int, 3> temp = pq.top(); pq.pop();
            if(d[temp[1]] && d[temp[2]]) {
                d[temp[1]]--;
                d[temp[2]]--;
                sum += temp[0];
            }
        }
    }
    cout << sum;
    // Consider example -> 
    // 1 - 2 - 3 - 4
    // 1 <= i <= 4 => d_i = 1
    // Weight of edge 1 - 2 => 2
    // ..             2 - 3 => 3
    // ..             3 - 4 => 2
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
