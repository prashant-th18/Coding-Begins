#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)

// We are assuming that our graph is DAG
int n;
vector<vector<int>> v;
vector<bool> vis;
vector<int> temp;
void dfs(int node) {
	vis[node] = true;
	for(auto val : v[node]) {
		if(!vis[val]) {
			dfs(val);
		}
	}
	temp.push_back(node);
}
vector<int> topologicalSort() {
	vector<int> order;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i);
			for(auto val : temp) order.push_back(val);
			temp.clear();
		}
	}
	reverse(all(order));
	return order;
}
int main() {
	cin >> n;
	int m; cin >> m;
	v.assign(n + 1, vector<int>());
	vis.assign(n + 1, false);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		// Directed Edge from a -> b
		v[a].push_back(b);
	}
	vector<int> order;
	order = topologicalSort();
	for(auto val : order) cout << val << ' ';
	return 0;
}