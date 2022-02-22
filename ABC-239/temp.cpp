#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
vector<ordered_set> v;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> value;
void dfs(int node)
{
    vis[node] = true;
    ordered_set myset; myset.insert(-value[node]);
    auto temp = [&]() -> void
    {
        while(sz(myset) > 20) myset.erase(*myset.rbegin());  
    };
    for(const auto& val : adj[node])
    {
        if(!vis[val])
        {
            dfs(val);
            auto& t = v[val];
            for(auto & valv : t)
            {
                myset.insert(valv);
                temp();
            }
        }
    }
    v[node] = myset;
}
// *-> KISS*
int solve() {
        int n, q; cin >> n >> q;
        value.assign(n + 1, 0);
        for(int i = 1; i <= n; ++i) cin >> value[i];
        v = vector<ordered_set>(n + 1);
        adj.assign(n + 1, vector<int>());
        vis.assign(n + 1, false);
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1);
        while(q--)
        {
            int node, k; cin >> node >> k;
            --k;
            cout << -*v[node].find_by_order(k) << '\n';
        } 
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
