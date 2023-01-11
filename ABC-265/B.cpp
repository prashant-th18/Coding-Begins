#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	ll n, m, t; cin >> n >> m >> t;
	vector<ll> v(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> v[i];
	}
	map<ll, ll> mp;
	for(int i = 0; i < m; ++i) {
		ll a, b; cin >> a >> b;
		mp[a - 1] = b;
	}
	int i = 0;
	while(i < n - 1 && t > 0) {
		if(mp.count(i)) {
			t += mp[i];
		}
		t -= v[i];
		++i;
	}
	if(i == n - 1 && t > 0) cout << "Yes";
	else cout << "No";
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
