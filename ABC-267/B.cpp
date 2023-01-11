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
	int n = 7;
	string s; cin >> s;
	vector<int> v(n, 0);
	map<int, int> mp;
	mp[6] = 0; mp[3] = 1; mp[7] = mp[1] = 2; mp[4] = mp[0] = 3; mp[8] = mp[2] = 4; mp[5] = 5; mp[9] = 6;
	for(int i = 0; i < 10; ++i) {
		v[mp[i]]++;
	}
	for(int i = 0; i < sz(s); ++i) {
		int c = mp[i];
		int t = s[i] - '0';
		v[c] -= (1 - t);
	}
	if(s[0] != '0') {
		cout << "No";
	}
	else {
		for(int i = 0; i < 7; ++i) {
			for(int j = i + 1; j < 7; ++j) {
				if(v[i] != 0 && v[j] != 0) {
					bool f = false;
					for(int k = i + 1; k < j; ++k) {
						f |= (v[k] == 0);
					}
					if(f) {
						cout << "Yes"; return 0;
					}
				}
			}
		}
		cout << "No";
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
