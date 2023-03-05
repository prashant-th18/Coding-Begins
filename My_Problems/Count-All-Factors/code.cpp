#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

const int N = 1e7 + 1;
vector<int> spf(N, -1);
vector<bool> pres(N, false);
void init() {
	for(int i = 2; i * i < N; ++i) {
		if(spf[i] == -1) {
			for(int j = 2 * i; j < N; j += i) {
				if(spf[j] == -1) spf[j] = i;
			}
		}
	}
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init(); // SPF Array initialised
	int n; cin >> n;
	assert(1 <= n && n <= (int)1e5); // Size Checked
	for(int i = 0; i < n; ++i) {
		int t; cin >> t; // i-th element taken
		assert(2 <= t && t <= 9999889); // Input Checked
		pres[t] = true;
	}
	int q; cin >> q;
	assert(1 <= q && q <= (int)1e6); // Queries Checked
	while(q--) {
		int k; cin >> k;
		assert(1 <= k && k <= (int)1e7); // k Checked
		map<int, ll> mp;
		while(k != 1) {
			int num = spf[k];
			if(num == -1) mp[k] = 1, k = 1;
			else {
				int c = 0;
				while(k % num == 0) k /= num, ++c;
				mp[num] = c;
			}
		}
		ll total = 1;
		for(const auto& [x, y] : mp) {
			total *= (y + 1);
		}
		ll ans = 0;
		for(const auto& [x, y] : mp) {
			if(pres[x]) {
				ans += (total / (y + 1) * y);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
// -> Keep It Simple Stupid!
