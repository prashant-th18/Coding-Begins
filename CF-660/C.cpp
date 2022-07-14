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

int n, m;
vector<ll> p, h;
vector<vector<ll>> v;
vector<array<ll, 2>> c; // [0] -> good, [1] -> bad
bool dfs(int node, int par = -1) {
    ll g = 0, b = p[node];
    for(const auto& val : v[node]) {
        if(val == par) continue;
        if(!dfs(val, node)) return false;
        g += c[val][0], b += c[val][1];
    }
    ll value = g - b;
    ll diff = h[node] - value;
    
    if(abs(diff) & 1) return false;
    
    if(diff >= 0) {
        if(diff / 2 <= p[node]) {
            g += diff / 2;
            b -= diff / 2;
        }
        else {
            g += p[node];
            b -= p[node];
            diff -= p[node] * 2;
            if(diff > b * 2) return false;
            g += diff / 2;
            b -= diff / 2;
        }
    }
    else {
        return false;
    }
    c[node][0] = g;
    c[node][1] = b;
    return true;
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    p.assign(n + 1, 0); h.assign(n + 1, 0);
    v.assign(n + 1, vector<ll>());
    c.assign(n + 1, array<ll, 2>{0, 0});
    for (int i = 0; i < n; i++) {
        cin >> p[i + 1];
    }
    for (int i = 0; i < n; i++) {
        cin >> h[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(dfs(1, -1)) cout << "Yes";
    else cout << "No";
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
