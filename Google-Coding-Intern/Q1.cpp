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
	ll a, b, c; cin >> a >> b >> c;
	ll x = 0;
	for(int i = 0; i < 63; ++i) {
		int i1 = (a >> i) & 1LL, i2 = (b >> i) & 1LL;
		if(c & (1LL << i)) {
			// This bit is set in "C"
			if(i1 & i2) {
				continue;
			}
			else {
				x += (1LL << i);
			}
		}
		else {
			// This bit is not set in "C"
			if(i1 & i2) {
				cout << -1; return 0;
			}
			else {
				continue;
			}
		}
	}
	cout << x;
	return 0;
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool test = true;
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
