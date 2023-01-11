#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define debug(...)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	string s; cin >> s;
	auto getValue = [&](string t) {
		ll sum = 0;
		for(int i = 0; i < sz(t); ++i) {
			sum += (t[i] - 'a' + 1);
		}
		return sum;
	};
	if(sz(s) % 2 == 0) {
		cout << "Alice " << getValue(s);
	}
	else {
		ll tot = getValue(s);
		string s1 = s.substr(0, sz(s) - 1), s2 = s.substr(1);
		ll s = max(getValue(s1), getValue(s2));
		ll diff = tot - s;
		if(s > diff) {
			cout << "Alice " << s - diff;
		}
		else {
			cout << "Bob " << diff - s;
		}
	}
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
