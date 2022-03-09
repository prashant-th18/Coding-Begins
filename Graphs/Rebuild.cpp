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
const ll inf = 1000000000000;
vector<ll> parent;
struct edge {
    ll a = inf, b = -1; // weight, node
    bool operator<(const edge& other) const
    {
        if(a != other.a)
        {
            return a < other.a;
        }
        ll max1 = max(b, parent[-b]);
        ll max2 = max(other.b, parent[-other.b]);
        return max1 < max2;
    }
};
// *-> KISS*
int solve() {
    ll n, m, ans {}; cin >> n >> m;
    vector<vector<pair<ll, ll>>> v(n + 1);
    parent.assign(n + 1, -1);
    set<edge> st;
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    vector<edge> min_e(n + 1);
    vector<bool> vis(n + 1, false);
    min_e[1].a = 0;
    st.insert({0, -1});
    vector<ll> degree(n + 1, 0);
    for (int i = 0; i < n; i++) {
        assert(sz(st) != 0);
        int node = -(st.begin()->b);
        if(node != 1)
        {
            degree[node]++;
            degree[min_e[node].b]++;
        }
        vis[node] = true;
        ans += st.begin()->a;
        st.erase(st.begin());
        for(const auto& [nei, w] : v[node])
        {
            if(!vis[nei])
            {
                if(w < min_e[nei].a)
                {
                    auto present = st.find({min_e[nei].a, -nei});
                    if(present != st.end())
                    {
                        st.erase(present);
                    }
                    min_e[nei].a = w;
                    st.insert({w, -nei});
                    min_e[nei].b = node;
                    parent[nei] = -node;
                }
            }
        }
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i) cout << degree[i] << ' ';
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
