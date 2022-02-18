#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<pair<ll, ll>>> v(n + 1);
        for (int i = 0; i < m; i++) {
            ll a, b, w; cin >> a >> b >> w;
            v[a].push_back({b, w});
            v[b].push_back({a, w});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 1});
        vector<ll> dist(n + 1, 1e18); dist[1] = 0;
        while(!pq.empty())
        {
            ll cur_node = pq.top().ss;
            ll curr = pq.top().ff;
            pq.pop();
            for(const auto& [x, y] : v[cur_node])
            {
                if(curr + y < dist[x])
                {
                    dist[x] = curr + y;
                    pq.push({dist[x], x});
                }
            }
        }
        if(dist[n] == (ll)1e18) cout << -1;
        else
        {
            vector<ll> path;
            ll node = n;
            while(node != 1)
            {
                path.push_back(node);
                for(const auto& [x, y] : v[node])
                {
                    if(dist[node] - y == dist[x])
                    {
                        node = x; break;
                    }
                }
            }
            path.push_back(1);
            reverse(all(path));
            for(auto val : path) cout << val << ' ';
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
