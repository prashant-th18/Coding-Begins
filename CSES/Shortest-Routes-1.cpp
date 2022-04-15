#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
vector<vector<pll>> v;
int main() {
    int n, m; cin >> n >> m;
    v.assign(n + 1, vector<pll>());
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    vector<ll> dist(n + 1, (ll)1e16);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    // dist, node
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(dis != dist[node]) continue;
        for(const auto& [ngh, d] : v[node]) {
            if(d + dist[node] < dist[ngh])
            {
                dist[ngh] = d + dist[node];
                pq.push({dist[ngh], ngh});
            }
        }
    }
    for(int i = 1; i <= n; ++i) cout << dist[i] << ' ';
    return 0;
}
