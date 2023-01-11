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
	int n; cin >> n;
	ll p, q, r; cin >> p >> q >> r;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<ll> pre(n);
	for (int i = 0; i < n; i++) {
		pre[i] = v[i] + (i == 0 ? 0 : pre[i - 1]);
	}
	set<int> st3, st2, st1;
	for(int i = n - 1; i >= 0; --i) {
		ll how3 = (i == 0 ? 0 : pre[i - 1]) + r;
		int in1 = lower_bound(all(pre), how3) - begin(pre);
		if(in1 == n || pre[in1] != how3) {}
		else st3.insert(i);
		ll how2 = (i == 0 ? 0 : pre[i - 1]) + q;
		int in2 = lower_bound(all(pre), how2) - begin(pre);
		if(in2 == n || pre[in2] != how2 || !st3.count(in2 + 1)) {}
		else st2.insert(i);
		ll how1 = (i == 0 ? 0 : pre[i - 1]) + p;
		int in3 = lower_bound(all(pre), how1) - begin(pre);
		if(in3 == n || pre[in3] != how1 || !st2.count(in3 + 1)) {}
		else {
			cout << "Yes"; return 0;
		}
	}
	debug(st1, st2, st3);
	cout << "No";
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
