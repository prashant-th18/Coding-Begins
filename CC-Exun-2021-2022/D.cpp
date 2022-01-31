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
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> v(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ++m; // m is increased
    vector<ll> time(m);
    for (int i = 1; i < m; i++) {
        cin >> time[i];
    }
    vector<ll> dist(n + 1, 0);
    vector<ll> leaf;
    function<void(ll, ll)> dfs = [&](ll node, ll dis) -> void
    {
        vis[node] = true;
        int children = 0;
        dist[node] = dis;
        for(const auto& val : v[node])
        {
            if(!vis[val])
            {
                ++children;
                dfs(val, dist[node] + 1);
            }
        }
        if(children == 0)
        {
            leaf.push_back(node);
        }
    };
    vector<ll> diff;
    for(int i = 0; i < m - 2; ++i)
    {
        diff.push_back(time[i + 1] - time[i]);
    }
    sort(diff.begin(), diff.end());
    dfs(1, 0);
    ll sum = 0;
    for(int i = 0; i < sz(leaf); ++i)
    {
        ll temp = 0, num = 0;
        temp += (time[m - 1] - dist[leaf[i]]);
        auto it = lower_bound(all(diff), dist[leaf[i]]);
        
        num = sz(diff) - (it - diff.begin());
        if(m != 2)
        {
            num = max(1LL, num);
        }
        
        temp -= num * dist[leaf[i]];
        temp = max(temp, 0LL);
        sum += temp;
    }
    cout << sum;
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
}
// -> Keep It Simple Stupid!
