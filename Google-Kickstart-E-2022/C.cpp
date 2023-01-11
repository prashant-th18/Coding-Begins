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
	string ip; cin >> ip;
	string s = "#";
	for(int i = 0; i < n; ++i) {
		s += ip[i];
		s += '#';
	}
	n = sz(s);
	s = '$' + s;
	s += '^';
	vector<int> p(n + 2);
	{int l = 1, r = 1;
		for(int i = 1; i <= n; i++) {
			p[i] = max(0, min(r - i, p[l + (r - i)]));
			while(s[i - p[i]] == s[i + p[i]]) {
				p[i]++;
			}
			if(i + p[i] > r) {
				l = i - p[i], r = i + p[i];
			}
		}
	}
	n = sz(s);
	for(int i = 2; i < n - 2; ++i) {
		int ss = p[i];
		int l = i - ss + 1;
		int u = i + ss;
		if(l == 1) {
			int lll = n - 3;
			int mid = (lll + u) >> 1;
			int aa = 2 * p[mid] - 1;
			if(aa >= (lll - u) + 1) {
				string ans = "";
				for(int ii = l ; ii < u; ++ii) {
					if(s[ii] != '#') {
						ans += s[ii];
					}
				}
				cout << ans;
				return 0;
			}
		}
	}
	string ans = "";
	for(int i = 1; i < n - 1; ++i) {
		if(s[i] != '#') ans[i] += s[i];
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
