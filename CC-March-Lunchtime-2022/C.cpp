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

vector<vector<int>> v;
vector<int> vis;
queue<int> dq;
void dfs(int node, int ti)
{
    if(ti >= 1)
    {
        vis[node] = 2;
    }
    else
    {
        vis[node] = 1;
        dq.push(node);
        return;
    }
    for(const auto& val : v[node])
    {
        if(vis[val] <= 1)
        {
            dfs(val, ti - 1);
        }
    }
}
// *-> KISS*
int solve() {
    dq = queue<int>();
    int n, m, q; cin >> n >> m >> q;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while(q--)
    {
        int query, x; cin >> query >> x;
        if(query == 1)
        {
            dq.push(x);
        }
        else if(query == 3)
        {
            if(vis[x] == 0) cout << "No";
            else cout << "Yes";
            cout << '\n';
        }
        else
        {
            queue<int> qq = dq;
            dq = queue<int>();
            while(!qq.empty())
            {
                dfs(qq.front(), x);
                qq.pop();
            }

        }
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
