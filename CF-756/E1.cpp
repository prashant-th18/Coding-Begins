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
vector<bool> friends, vis;
vector<vector<int>> v;
vector<int> dist, parent;
void dis(int node, int d, int p = -1)
{
    parent[node] = p;
    vis[node] = true;
    dist[node] = d;
    for(const auto& val : v[node])
    {
        if(!vis[val])
        {
            dis(val, d + 1, node);
        }
    }
}
vector<ll> dp;
void apply(int node)
{
    int op = 0;
    while(node != -1)
    {
        if(dp[node] <= op)
        {
            return;
        }
        dp[node] = op; ++op;
        node = parent[node];
    }
}
bool dfs(int node, int dis)
{
    vis[node] = true;
    if(dp[node] <= dis)
    {
        return false;
    }
    int c = 0;
    for(const auto& val : v[node])
    {
        if(!vis[val])
        {
            ++c;
            if(dfs(val, dis + 1)) return true;
        }
    }
    if(c == 0)
    {
        return true;
    }
    return false;
}
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    friends.assign(n + 1, false);
    vector<ll> all_f;
    for (int i = 0; i < k; i++) {
        int t; cin >> t;
        friends[t] = true;
        all_f.push_back(t);
    }
    vis.assign(n + 1, false);
    v.assign(n + 1, vector<int>());
    dist.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> empty;
    dis(1, 0);
    vis.assign(n + 1, false);
    dp.assign(n + 1, LLONG_MAX);
    sort(all_f.begin(), all_f.end(), [&](int a, int b) -> bool { return dist[a] < dist[b]; });
    for (int i = 0; i < sz(all_f); i++) {
        apply(all_f[i]);
    }
    if(dfs(1, 0)) cout << "Yes";
    else cout << "No";
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
