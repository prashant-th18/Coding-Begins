#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll n, maxx = LLONG_MIN;
vector<ll> v;
void fun(int index, ll sum) {
	sum += v[index];
	if(index == n - 1) {
		maxx = max(maxx, sum); return;
	}
	for(int i = 0; i < 28; ++i) {
		ll ni = index + (1 << i);
		if(ni < n) {
			fun(ni, sum);
		}
		else return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		maxx = LLONG_MIN;
		cin >> n;
		v.assign(n, 0);
		for(int i = 0; i < n; ++i) cin >> v[i];
		fun(0, 0);
		cout << maxx << '\n';
	}
	return 0;
}
