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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	int n, q; cin >> n >> q;
	vector<int> bit(n + 1, 0);
	auto sum = [&](int r) -> int {
		int s = 0;
		for(; r > 0; r -= (r & (-r))) {
			s += bit[r];
		}
		return s;
	};
	auto upd = [&](int l, int del = 1) -> void {
		for(; l <= n; l += (l & (-l))) {
			bit[l] += del;
		}
	};
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		upd(t);
	}
	for(int i = 0; i < q; ++i) {
		int k; cin >> k;
		if(k < 0) {
			k *= -1;
			int s = 1, e = n, ans = 0;
			while(s <= e) {
				int mid = (s + e) >> 1;
				int temp = sum(mid);
				if(temp < k) {
					s = mid + 1;
				}
				else {
					ans = mid;
					e = mid - 1;
				}
			}
			assert(ans != 0);
			upd(ans, -1);
		}
		else {
			upd(k);
		}
	}
	if(sum(n) == 0) cout << 0;
	else {
		for(int i = 1; i <= n; ++i) {
			if(sum(i) > 0) {
				cout << i; break;
			}
		}
	}
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
