#include <bits/stdc++.h>
using namespace std;

int n, maxx = -1, last = -1;
vector<vector<int>> v;
vector<int> par, h;
vector<bool> vis;
void dfs(int node, int p, int lvl) {
	vis[node] = true;
	par[node] = p;
	h[node] = max(h[node], lvl);
	if(lvl >= maxx) {
		maxx = lvl;
		last = node;
	}
	for(int& val : v[node]) {
		if(!vis[val]) {
			dfs(val, node, lvl + 1);
		}
	}
}
int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n;
	v.assign(n + 1, vector<int>());
	par.assign(n + 1, -1);
	h.assign(n + 1, 0);
	vis.assign(n + 1, false);
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, -1, 0);
	vis.assign(n + 1, false);
	dfs(last, -1, 0);
	vis.assign(n + 1, false);
	vector<int> order;
	int cnt = 0;
	while(last != -1) {
		order.push_back(last);
		h[last] = max(cnt, maxx - cnt);
		++cnt;
		vis[last] = true;
		last = par[last];
	}
	for(const auto& val : order) {
		dfs(val, -1, h[val]);
	}
	for(int i = 1; i <= n; ++i) cout << h[i] << ' ';
	return 0;
}
