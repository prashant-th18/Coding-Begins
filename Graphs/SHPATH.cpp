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
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        vector<vector<pair<ll, ll>>> v(n + 1);
        unordered_map<string, int> index;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            index[s] = i + 1;
            int m; cin >> m;
            for (int j = 0; j < m; j++) {
                ll a, w; cin >> a >> w;
                v[i + 1].push_back({a, w});
            }
        }
        auto dijkstra = [&](string source, string dest) -> ll
        {
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
            pq.push({0, index[source]});
            vector<ll> dist(n + 1, 1e12); dist[index[source]] = 0;
            while(!pq.empty())
            {
                int dis = pq.top().ff;
                int node = pq.top().ss;
                pq.pop();
                if(dis != dist[node]) continue;
                for(auto &[x, y] : v[node])
                {
                    if(y + dis < dist[x])
                    {
                        dist[x] = y + dis;
                        pq.push({dist[x], x});
                    }
                }
            }
            return dist[index[dest]];
        };
        int r = 0; cin >> r;
        for (int i = 0; i < r; i++) {
            string a, b; cin >> a >> b;
            cout << dijkstra(a, b) << '\n';
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
