#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	int q; cin >> q;
	while(q--) {
		int k; cin >> k;
		vector<int> d;
		for(int i = 1; i * i <= k; ++i) {
			if(k % i == 0) {
				d.push_back(i);
				if(i != k / i) d.push_back(k / i);
			}
		}
		ll sum = 0;
		for(int j = 0; j < sz(d); ++j) {
			for(int i = 0; i < n; ++i) {
				if(d[j] % v[i] == 0) ++sum;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
// -> Keep It Simple Stupid!
