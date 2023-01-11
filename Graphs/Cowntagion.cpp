#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)

int n;
vector<vector<int>> v;
vector<int> order;

ll ans = 0;
void dfs(int node, int par) {
	// Ek cow toh yhi chahiye aur abhi present mere paas 1 hai
	int how = 0;
	for(int& val : v[node]) how += (val != par);

	int index = upper_bound(all(order), how) - begin(order);
	ans += index;
	for(int & val : v[node]) {
		if(val != par) {
			++ans;
			dfs(val, node);
		}
	}
}
int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n;
	v.assign(n + 1, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 0; i < 28; ++i) order.push_back(1 << i);
	dfs(1, -1);
	cout << ans;
	return 0;
}
