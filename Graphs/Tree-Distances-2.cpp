#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> v;
vector<ll> nodes, value, ans;
void init(int node, int par) {
	int cnt = 1;
	ll sum = 0;
	for(int& val : v[node]) {
		if(val != par) {
			init(val, node);
			sum += (nodes[val] + value[val]);
			cnt += nodes[val];
		}
	}
	nodes[node] = cnt;
	value[node] = sum;
}
void dfs(int node, int par) {
	ans[node] = value[node];
	for(int& val : v[node]) {
		if(val != par) {
			ll toSub = nodes[val] + value[val];
			value[node] -= toSub;
			nodes[node] -= nodes[val];
			value[val] += (value[node] + nodes[node]);
			nodes[val] += nodes[node];

			dfs(val, node);

			nodes[val] -= (nodes[node]);
			value[val] -= (value[node] + nodes[node]);
			nodes[node] += nodes[val];
			value[node] += toSub;
		}
	}
}
int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n;
	v.assign(n + 1, vector<int>());
	nodes.assign(n + 1, 0);
	value.assign(n + 1, 0);
	ans.assign(n + 1, 0);
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	init(1, 0);
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	return 0;
}
