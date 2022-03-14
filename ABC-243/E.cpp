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
vector<vector<vector<ll>>> v;
struct edge {
    ll d, prior, myn;
    bool operator<(const edge& other) const
    {
        if(d != other.d) return d < other.d;
        return prior > other.prior;
    }
};
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    v = vector<vector<vector<ll>>>(n + 1);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        vector<ll> temp = {b, c, 0}
        v[a].push_back(temp);
        temp.clear();
        temp.push_back(a); temp.push_back(c); temp.push_back(0);
        v[b].push_back(temp);
    }
    auto dijkstra = [&](int node) -> void
    {
        vector<int> par(n + 1, -1);
        vector<ll> dist(n + 1, LLONG_MAX);
        dist[node] = 0;
        set<edge> st;
        st.insert({0, 0, node});
        while(!st.empty())
        {
            ll dis = st.begin()->d;
            ll t = t.begin()->myn;
            st.erase(st.begin());
            if(dis != dist[t]) continue;
            for(const auto & val : v[node])
            {
                if(val[1] + dis < dist[val[0]])
                {
                    dist[val[0]] = val[1] + dis;
                    st.insert({dist[val[0]], val[2], val[0]});
                    par[val[0]] = node;
                }
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i == node) continue;

            int p = par[i], cur = i;
            while(p != -1)
            {
                 
            }
        }
    };
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
