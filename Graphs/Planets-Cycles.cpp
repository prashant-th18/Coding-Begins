#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using ll = long long;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int n; cin >> n;
	vector<int> succ(n, 0), ans(n, 0), in(n, 0);

	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		--t;
		succ[i] = t;
		in[t]++;
	}
	set<int> st;
	for(int i = 0; i < n; ++i) st.insert(i);

	queue<int> keep, q;
	for(int i = 0; i < n; ++i) {
		if(in[i] == 0) {
			q.push(i);
			st.erase(i);
		}
	}
	keep = q;
	
	while(!q.empty()) {
		int t = q.front(); q.pop();
		if(--in[succ[t]] == 0) {
			q.push(succ[t]);
			st.erase(succ[t]);
		}
	}

	// Now st will have only those elements which are in a cyclic loop
	for(auto& val : st) {
		if(ans[val] == 0) {
			vector<int> order;
			int node = succ[val];
			order.push_back(val);
			int len = 1;
			while(node != val) order.push_back(node), node = succ[node], ++len;
			
			for(auto& vall : order) ans[vall] = len;
		}
	}

	q = keep;
	while(!q.empty()) {
		int t = q.front(); q.pop();
		vector<int> order;
		while(ans[t] == 0) {
			order.push_back(t);
			t = succ[t];
		}
		reverse(all(order));
		debug(order);
		int len = ans[t] + 1;
		for(auto val : order) ans[val] = len++;
	}

	for(auto val : ans) cout << val << ' ';
	return 0;
}
