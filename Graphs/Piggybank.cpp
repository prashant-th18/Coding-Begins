#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define ff first
#define ss second

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
	ll b, e, p, n, m;
	cin >> b >> e >> p >> n >> m;
	vector<vector<ll>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		int u, z; cin >> u >> z;
		v[u].push_back(z);
		v[z].push_back(u);
	}
	auto f = [&](int start, vector<bool>& vis, vector<ll>& dis, ll w) {
		queue<pll> q;
		q.push({start, 0});
		dis[start] = 0;
		vis[start] = true;
		while(!q.empty()) {
			pll pi = q.front(); q.pop();
			for(ll& val : v[pi.ff]) {
				if(!vis[val]) {
					vis[val] = true;
					dis[val] = dis[pi.ff] + w;
					q.push({val, dis[val]});
				}
			}
		}
	};
	vector<bool> vis1(n + 1, false), vis2(n + 1, false), vis3(n + 1, false);
	vector<ll> dis1(n + 1), dis2(n + 1), dis3(n + 1);
	f(1, vis1, dis1, b);
	f(2, vis2, dis2, e);
	f(n, vis3, dis3, min(b + e, p));
	ll minn = LLONG_MAX;
	for(int i = 1; i <= n; ++i) {
		if(vis1[i] && vis2[i] && vis3[i]) {
			minn = min(minn, dis1[i] + dis2[i] + dis3[i]);
		}
	}
	cout << minn;
	return 0;
}
