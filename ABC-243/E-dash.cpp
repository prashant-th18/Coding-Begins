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
struct edge {
    ll d, prior, node;
    bool operator<(const edge& other) const
    {
        if(d != other.d) return d < other.d;
        return -prior < -other.prior;
    }
};
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<vector<array<ll, 2>>> v(n + 1, vector<array<ll, 2>>(n + 1, {0, 0}));
    // Cost, Priority
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        v[a][b][0] = c;
        v[b][a][0] = c;
    }
    auto dijkstra = [&](int node) -> void
    {
        vector<ll> dist(n + 1, LLONG_MAX);
        vector<ll> par(n + 1, -1);
        dist[node] = 0;
        set<edge> st;
        st.insert({0, 0, node});
        while(!st.empty())
        {
            ll d = st.begin()->d;
            ll temp = st.begin()->node;
            st.erase(st.begin());
            if(d != dist[temp]) continue;
            for(int i = 1; i <= n; ++i)
            {
                if(i == temp) continue;
                if(v[temp][i][0] != 0)
                {
                    if(d + v[temp][i][0] <= dist[i])
                    {
                        dist[i] = d + v[temp][i][0];
                        st.insert({dist[i], v[temp][i][1], i});
                        par[i] = temp;
                    }
                }
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i == node) continue;
            
            int cur = i;
            int p = par[cur];
            while(p != -1)
            {
                v[p][cur][1]++;
                v[cur][p][1]++;
                cur = p;
                p = par[cur];
            }
        }
    };
    int cnt = 0;
    for(int i = 1; i <= n; ++i) dijkstra(i);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            if(v[i][j][0] != 0)
            {
                cnt += (v[i][j][1] != 0);
            }
        }
    }
    cerr << v[4][5][1] << endl << endl;
    cout << max(0, m - cnt);
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
