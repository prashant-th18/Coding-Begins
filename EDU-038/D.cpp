#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define ff first
#define ss second
#define all(x) begin(x), end(x)

const ll inf = LLONG_MAX;
int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<vector<pll>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		ll a, b, c; cin >> a >> b >> c;
		v[a].push_back(pll(b, c));
		v[b].push_back(pll(a, c));
	}
	vector<ll> values(n + 1, 0);
	for(int i = 0; i < n; ++i) cin >> values[i + 1];
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for(int i = 0; i < n; ++i) {
		pq.push({values[i + 1], i + 1});
	}
	vector<ll> dist(n + 1, inf);
	while(!pq.empty()) {
		pll t = pq.top(); pq.pop();
		if(dist[t.ss] <= t.ff) continue;
		dist[t.ss] = t.ff;
		for(const auto& [node, w] : v[t.ss]) {
			if(dist[node] > t.ff + 2 * w) {
				pq.push({t.ff + 2 * w, node});
			}
		}
	}
	for(int i = 1; i <= n; ++i) cout << dist[i] << ' ';
	return 0;
}