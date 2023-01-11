#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout); 
	int n; cin >> n;
	vector<int> succ(n, 0), in(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> succ[i];
		--succ[i];
		in[succ[i]]++;
	}
	int ans = n;
	queue<int> q;
	for(int i = 0; i < n; ++i) if(in[i] == 0) q.push(i), --ans;
	while(!q.empty()) {
		int t = q.front(); q.pop();
		if(--in[succ[t]] == 0) {
			--ans;
			q.push(succ[t]);
		}
	}
	cout << ans;
	return 0;
}
