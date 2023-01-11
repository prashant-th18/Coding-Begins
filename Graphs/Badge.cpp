#include <bits/stdc++.h>
using namespace std;

int main() {
	// Used Floyd Algorithm
	int n; cin >> n;
	vector<int> succ(n, 0), in(n, 0), ans(n, 0);
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		--t;
		succ[i] = t;
		if(t != i) in[t]++;
	}
	queue<int> q;
	for(int i = 0; i < n; ++i) if(in[i] == 0) q.push(i);

	if(q.size() == 0) q.push(1);

	while(!q.empty()) {
		int t = q.front(); q.pop();

		int start = t;
		int a = t, b = t;
		a = succ[a], b = succ[succ[b]];
		while(a != b) {
			a = succ[a];
			b = succ[succ[b]];
		}
		a = start;
		vector<int> order1;
		while(a != b) {
			order1.push_back(a);
			a = succ[a], b = succ[b];
		}
		// a is the start of the loop
		for(auto& val : order1) {
			ans[val] = a;
		}
		order1.clear();
		order1.push_back(b);
		b = succ[a];
		while(a != b) {
			order1.push_back(b);
			b = succ[b];
		}
		for(auto val : order1) ans[val] = val;
	}
	for(int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
	return 0;
}
