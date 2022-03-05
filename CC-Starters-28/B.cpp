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
vector<int> dist;
void bfs(int n)
{
    // dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n});
    dist[n] = 0;
    while(!pq.empty())
    {
        auto f = pq.top();
        int x = f.first;
        int y = f.second;
        pq.pop();
        if(dist[y] != x)
        {
            continue;
        }
        for(const auto& val : v[y])
        {
            if(x < dist[val])
            {
                dist[val] = x;
                pq.push({x, val});
            }
        }
        if(y - 1 > 0)
        {
            if(x + 1 < dist[y - 1])
            {
                dist[y - 1] = x + 1;
                pq.push({dist[y - 1], y - 1});
            }
        }
        if(y + 1 < n && (x + 1 < dist[y + 1]))
        {
            dist[y + 1] = x + 1;
            pq.push({x + 1, y + 1});
        }
    }
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    v.assign(n + 1, vector<int>());
    dist.assign(n + 1, INT_MAX);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(n);
    cout << dist[1];
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
