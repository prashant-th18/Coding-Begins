#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	int n, m; cin >> n >> m;
	vector<int> money(n), bank(m);
	unordered_map<int, vector<int>, custom_hash> have;
	for(int i = 0; i < n; ++i) {
		cin >> money[i];
		have[money[i]].push_back(i);
	}
	for(int i = 0; i < m; ++i) cin >> bank[i];
	// Since at-most 20 bank-notes, I will use bit-masking
	vector<vector<int>> avail(n);
	// avail[i][j] -> For i, using j subset, I an make i
	for(int j = 0; j < (1 << m); ++j) {
		int sum = 0;
		for(int k = 0; k < m; ++k) {
			if(j & (1 << k)) sum += bank[k];
		}
		for(auto val : have[sum]) {
			// val are indices
			avail[val].push_back(j);
		}
	}
	vector<vector<bool>> dp(n + 1, vector<bool>(1 << m, false));
	for(int i = n; i >= 0; --i) {
		for(int j = 0; j < (1 << m); ++j) {
			if(i == n) {
				dp[i][j] = true;
			}
			else {
				for(auto val : avail[i]) {
					if((val & (j)) == val) {
						dp[i][j] = dp[i][j] | dp[i + 1][j ^ val];
						if(dp[i][j]) break;
					}
				}
			}
		}
	}
	cout << (dp[0][(1 << m) - 1] ? "YES" : "NO");
	return 0;
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool test = false;
	int TET = 1;
	if(test) cin >> TET;
	cout << fixed << setprecision(6);
	for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
		cout << "##################" << '\n';
#endif

		if (solve()) {
			break;
		}
		cout << '\n';
	}
#ifdef LOCAL
	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
// -> Keep It Simple Stupid!
