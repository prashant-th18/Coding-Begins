#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
struct Edge
{
    ll w = 1e10;
    ll p = -1;
    bool operator<(const Edge& other) const
    {
        return w < other.w;
    }
};
vector<vector<pair<ll, ll>>> adj;
void prim(int n)
{
    vector<Edge> min_e(n);
    vector<bool> in_mst(n, false);
    set<Edge> pq;
    pq.insert({0, 0});
    min_e[0].w = 0;
    ll total_weight = 0;
    for (int i = 0; i < n; i++) {
        ll v = pq.begin()->p;
        total_weight += pq.begin()->w;
        pq.erase(pq.begin());
        in_mst[v] = true;
        for(auto [node, weight] : adj[v])
        {
            if(!in_mst[node] && (min_e[node].w > weight))
            {
                auto present = pq.find({min_e[node].w, node});
                if(present != pq.end())
                {
                    pq.erase(present);
                }
                min_e[node].w = weight;
                min_e[node].p = v;
                pq.insert({weight, node});
            }
        }
    }
    cout << total_weight << '\n';
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n, m; cin >> n >> m;
        adj = vector<vector<pair<ll, ll>>>(n);
        for (int i = 0; i < m; i++) {
            ll a, b, c; cin >> a >> b >> c;
            --a;
            --b;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        prim(n);
    }
    return 0;
}
// -> Keep It Simple Stupid!
