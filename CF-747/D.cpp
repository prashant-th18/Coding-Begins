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
vector<array<vector<int>, 4>> v;
vector<bool> vis;
vector<int> path1, path2;
vector<int> order; // 0 -> imposter, 1 -> crewmate
vector<int> what;
bool dfs(int node, int k)
{
    vis[node] = true;
    what[node] = k;
    order.push_back(k);
    if(k == 0)
    {
        for(const auto& val : v[node][0])
        {
            if(!vis[val])
            {
                if(!dfs(val, 0)) return false;
            }
            else
            {
                if(what[val] != k) return false;
            }
        }
        for(const auto& val : v[node][1])
        {
            if(!vis[val]) { if(!dfs(val, 1)) return false; }
            else if(what[val] == k) return false;
        }
        for(const auto& val : v[node][2])
        {
            if(!vis[val]) { if(!dfs(val, 0)) return false; }
            else if(what[val] != 0) return false;
        }
        for(const auto& val : v[node][3])
        {
            if(!vis[val]) { if(!dfs(val, 1)) return false; }
            else if(what[val] == 0) return false;
        }
    }
    else
    {
        for(const auto& val : v[node][0])
        {
            if(!vis[val]) { if(!dfs(val, 1)) return false; }
            else if(what[val] == 0) return false;
        }
        for(const auto& val : v[node][1])
        {
            if(!vis[val]) { if(!dfs(val, 0)) return false; }
            else if(what[val] == 1) return false;
        }
        for(const auto& val : v[node][2])
        {
            if(!vis[val]) { if(!dfs(val, 1)) return false; }
            else if(what[val] == 0) return false;
        }
        for(const auto& val : v[node][3])
        {
            if(!vis[val]) { if(!dfs(val, 0)) return false; }
            else if(what[val] == 1) return false;
        }
    }
    return true;
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    v = vector<array<vector<int>, 4>>(n + 1);
    what.assign(n + 1, 0);
    order.clear();
    path1.clear(); path2.clear();
    // 
    // 0 -> mai jinhe crewmates maan rha hun
    // 1 -> mai jinhe imposters maan rha hun
    // 2 -> jo mujhe crewmate maan rhe hai
    // 3 -> jo mujhe imposter maan rhe hai
    for (int i = 0; i < m; i++) {
        int a, b; string s; cin >> a >> b >> s;
        if(s[0] == 'i') 
        {
            v[a][1].push_back(b);
            v[b][3].push_back(a);
        }
        else 
        {
            v[a][0].push_back(b);
            v[b][2].push_back(a);
        }
    }
    vis.assign(n + 1, false);
    int k = 0;
    auto fun = [&]() -> void
    {
        for(int i = 1; i <= n; ++i)
        {
            if(!vis[i])
            {
                bool flag = dfs(i, k);
                if(flag == false)
                {
                    if(k == 0)
                    path1.push_back(-1);
                    else
                    path2.push_back(-1);
                }
                else
                {
                    int c = 0;
                    for(auto val : order)
                    {
                        c += (val == 0);
                    }
                    if(k == 0)
                    path1.push_back(c);
                    else
                    path2.push_back(c);
                }
                order.clear();
            }
        }
        ++k;
    };
    fun();
    vis.assign(n + 1, false);
    what.assign(n + 1, 0);
    fun();
    ll ans = 0;
    for (int i = 0; i < sz(path1); i++) {
        int maxx = max(path1[i], path2[i]);
        if(maxx == -1)
        {
            cout << -1; return 0;
        }
        else
        {
            ans += maxx;
        }
    }
    cout << ans;
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
