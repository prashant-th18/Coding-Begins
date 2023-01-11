#include "bits/stdc++.h"
using namespace std;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
// Use -> unordered_map<key_type, value_type, custom_hash> mp;
using pii = pair<int, int>;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k, n; cin >> k >> n; // Knapsack size, size of the array
	unordered_map<int, int, custom_hash> value;
	for(int i = 0; i < n; ++i) {
		int a, b; cin >> b >> a;
		if(value[a] <= b) {
			value[a] = b;
		}
	}
	vector<pii> v;
	for(auto& val : value) {
		v.push_back(val);
	}
	n = (v.size());
	vector<vector<int>> dp(2, vector<int>(k + 1, 0));
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= k; ++j) {

		}
	}
	return 0;
}
