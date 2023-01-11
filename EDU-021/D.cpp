#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];

	auto get = [&]() {
		map<ll, int> mp;
		for(int i = 0; i < n; ++i) mp[v[i]]++;
		ll left = 0, right = accumulate(all(v), 0LL);
		for(int i = 0; i < n; ++i) {
			ll dif = right - left;
			if(dif % 2 == 0 && mp[dif / 2] != 0) {
				return true;
			}
			left += v[i];
			right -= v[i];
			mp[v[i]]--;
			dif = right - left;
			if(dif % 2 == 0 && mp[dif >> 1] != 0) {
				return true;
			}
		}
		return false;
	};
	if(get()) {
		cout << "YES"; return 0;
	}
	reverse(all(v));
	if(get()) {
		cout << "YES";
	}
	else cout << "NO";
	return 0;
}
