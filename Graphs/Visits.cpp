#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int n; cin >> n;
	vector<int> succ(n);
	vector<ll> value(n, 0);
	vector<int> in(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> succ[i]; --succ[i];
		cin >> value[i];
		++in[succ[i]];
	}
	queue<int> q;
	set<int> st;
	for(int i = 0; i < n; ++i) st.insert(i);

	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		if(in[i] == 0) {
			q.push(i);
			ans += value[i];
			st.erase(i);
		}
	}
	while(!q.empty()) {
		int t = q.front(); q.pop();
		if(--in[succ[t]] == 0) {
			q.push(succ[t]);
			ans += value[succ[t]];
			st.erase(succ[t]);
		}
	}

	vector<bool> vis(n, false);
	for(auto& val : st) {
		if(!vis[val]) {
			vis[val] = true;
			vector<ll> order;
			order.push_back(value[val]);
			int node = succ[val];
			while(node != val) {
				vis[node] = true;
				order.push_back(value[node]);
				node = succ[node];
			}
			sort(begin(order), end(order), greater<>());
			for(int i = 0; i < (int)order.size() - 1; ++i) ans += order[i];
		}
	}
	cout << ans;
	return 0;
}
