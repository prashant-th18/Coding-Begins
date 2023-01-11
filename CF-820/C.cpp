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
    string s; cin >> s;
	int n = sz(s);
	bool flag = false;
	if(s[0] > s[n - 1]) {
		reverse(all(s));
		flag = true;
	}
	vector<vector<int>> v(26);
	for(int i = 0; i < n; ++i) {
		int in = s[i] - 'a';
		if(flag) v[in].push_back(n - 1 - i);
		else {
			v[in].push_back(i);
		}
	}
	ll cost = s[n - 1] - s[0];
	vector<int> ans;
	for(int i = s[0] - 'a'; i <= s[n - 1] - 'a'; ++i) {
		for(int j = 0; j < sz(v[i]); ++j) {
			ans.push_back(v[i][j]);
		}
	}
	cout << cost << ' ' << sz(ans) << '\n';
	if(flag) reverse(all(ans));
	for(int i = 0; i < sz(ans); ++i) cout << ans[i] + 1 << ' ';
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
