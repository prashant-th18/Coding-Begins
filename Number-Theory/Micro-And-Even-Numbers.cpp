#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n, k; cin >> n >> k;
	vector<ll> fact(11, 1);
	for(ll i = 2; i < 11; ++i) {
		fact[i] = i * fact[i - 1];
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int e = count_if(begin(v), end(v), [&](int num) {
			return num % 2 == 0;
			});
	if(k > e) {
		cout << 0;
	}
	else {
		cout << fact[e] / fact[e - k] / fact[k];
	}
}
