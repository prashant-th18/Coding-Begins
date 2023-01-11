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
using pll = pair<ll, ll>;

pair<set<int>, int> get(pll a, pll b) {
	set<int> st;
	st.insert(a.ff); st.insert(a.ss); st.insert(b.ss); st.insert(b.ff);
	if(sz(st) != 3) return {st, -1};
	int cm = -1;
	if(a.ff == b.ff || a.ff == b.ss) cm = a.ff;
	if(a.ss == b.ff || a.ss == b.ss) cm = a.ss;
	return {st, cm};
}
// *-> KISS*
int solve() {
	int n, m; cin >> n >> m;
	vector<pll> a(n), b(m);
	for(int i = 0; i < n; ++i) cin >> a[i].ff >> a[i].ss;
	for(int i = 0; i < m; ++i) cin >> b[i].ff >> b[i].ss;

	set<int> every;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			// Consider pair "i" and "j"
			auto [here, cm] = get(a[i], b[j]);
			if(cm == -1) continue;
			// set in "here"
			// common number is "cm"
			for(int k = 0; k < n; ++k) {
				if(k == i) continue;
				auto [st, cp] = get(a[k], b[j]);
				if(cp == -1) continue;
				if(cp != cm) every.insert(-1);
			}
			for(int k = 0; k < m; ++k) {
				if(k == j) continue;
				auto [st, cp] = get(a[i], b[k]);
				if(cp == -1) continue;
				if(cp != cm) every.insert(-1);
			}
			every.insert(cm);
		}
	}
	if(every.empty()) {
		cout << -1; return 0;
	}
	int f = *(every.begin());
	if(f == -1) cout << -1;
	else if(sz(every) > 1) cout << 0;
	else cout << f;
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
