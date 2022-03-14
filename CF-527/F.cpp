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
vector<vector<ll>> v;
vector<ll> value;
vector<array<ll, 2>> temp; // Calculated Value, Sum of Subtree
// Initialization DFS
void init(int node, int p = -1)
{
    temp[node] = {0, value[node]};
    for(const auto & val : v[node])
    {
        if(val == p) continue;
        init(val, node);
        temp[node][1] += temp[val][1];
        temp[node][0] += (temp[val][0] + temp[val][1]);
    }
}
// Re-Rooting
ll dfs(int node, int p = -1)
{
    ll ans = temp[node][0];
    for(const auto& val : v[node])
    {
        if(val == p) continue;

        // Re-Rooting
        temp[node][0] -= (temp[val][0] + temp[val][1]);
        temp[node][1] -= temp[val][1];
        temp[val][0] += (temp[node][0] + temp[node][1]);
        temp[val][1] += temp[node][1];
        // Now "Val" is the root of the tree
        ans = max(ans, dfs(val, node));
        // Making "Node" the root again
        temp[val][1] -= temp[node][1];
        temp[val][0] -= (temp[node][0] + temp[node][1]);
        temp[node][1] += temp[val][1];
        temp[node][0] += temp[val][0] + temp[val][1];
    }
    return ans;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    value.assign(n + 1, 0);
    v.assign(n + 1, vector<ll>());
    temp.assign(n + 1, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> value[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    init(1);
    cout << dfs(1);
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
    return 0;
}
// -> Keep It Simple Stupid!
