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
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	int n; cin >> n;
	vector<pll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].ff;
		v[i].ss = i;
	}
	sort(v.begin(), v.end());
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(all(v), pll(2 * v[i].ff + 1, -1)) - begin(v);
		--ind;
		if(ind == i) {
			--ind;
			if(ind >= 0) {
				ans[v[i].ss] = v[ind].ff;
			}
			else ans[v[i].ss] = -1;
		}
		else {
			ans[v[i].ss] = v[ind].ff;
		}
	}
	for(int i= 0; i < n; ++i) cout << ans[i] << ' ';
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
		cout << "Case #" << i << ": ";
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
