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
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	multiset<int> st;
	for(int i = 0; i < n; ++i) st.insert(b[i]);
	vector<vector<int>> ans(n, vector<int>(2, 0)); // mini, maxi
	for(int i = n - 1; i >= 0; --i) {
		int ind = lower_bound(all(b), a[i]) - begin(b);
		ans[i][0] = b[ind] - a[i];
		if(i == n - 1) {
			ans[i][1] = b[n - 1] - a[i];
		}
		else {
			ans[i][1] = (*st.rbegin()) - a[i];
		}
		{
			auto it = st.lower_bound(b[ind]);
			assert(it != st.end());
			st.erase(it);
		}
	}
	for(int i = 0; i < n; ++i) cout << ans[i][0] << ' ';
	cout << '\n';
	for(int i = 0; i < n; ++i) cout << ans[i][1] << ' ';
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
