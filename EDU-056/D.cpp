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
#define MOD 998244353
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

vector<vector<int>> v;
vector<bool> vis;
vector<int> color;
vector<int> path;
bool dfs(int node, int col = 0)
{
    vis[node] = true; color[node] = col;
    path.push_back(col);
    for(const auto& val : v[node])
    {
        if(!vis[val])
        {
            if(!dfs(val, 1 - col)) return false;
        }
        else
        {
            if(color[val] == col) return false;
        }
    }
    return true;
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    v = vector<vector<int>> (n + 1);
    vis.assign(n + 1, false);
    color.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    auto binexp = [&](ll base, ll power) -> ll
    {
        ll res = 1;
        while(power)
        {
            if(power & 1)
            {
                res = res * base % MOD;
            }
            base = base * base % MOD;
            power >>= 1;
        }
        return res;
    };
    ll ans = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            if(!dfs(i))
            {
                path.clear();
                cout << 0; return 0;
            }
            ll temp = 0;
            ll a1 = 0;
            a1 += accumulate(all(path), 0LL);
            ll a2 = sz(path) - a1;
            temp = ((temp + binexp(2, a1)) % MOD + binexp(2, a2)) % MOD;
            ans = ans * temp % MOD;
            path.clear();
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
