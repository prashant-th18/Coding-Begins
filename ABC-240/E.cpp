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
vector<vector<int>> v;
vector<pair<int, int>> range;
int leaf = 1;
pair<int, int> dfs(int node, int parent)
{
    pair<int, int> temp = pair(INT_MAX, INT_MIN);
    int cc = 0;
    for(const auto& val : v[node])
    {
        if(val != parent)
        {
            ++cc;
            auto t1 = dfs(val, node);
            temp.ff = min(temp.ff, t1.ff);
            temp.ss = max(temp.ss, t1.ss);
        }
    }
    if(cc == 0) // Leaf Node
    {
        pair<int, int> t = pair(leaf, leaf);
        range[node] = t;
        ++leaf;
        return t;
    }
    return range[node] = temp;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    v.assign(n + 1, vector<int>());
    range = vector<pair<int, int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; ++i)
    {
        cout << range[i].ff << ' ' << range[i].ss << '\n';
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
