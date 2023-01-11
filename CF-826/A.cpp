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
    string a, b; cin >> a >> b;
	map<char, int> mp;
	mp['S'] = 1; mp['M'] = 2; mp['L'] = 3;
	int n = sz(a), m = sz(b);
	if(a[n - 1] != b[m - 1]) {
		if(mp[a[n - 1]] < mp[b[m - 1]]) {
			cout << "<";
		}
		else cout << ">";
		return 0;
	}
	if(sz(a) - 1 == sz(b) - 1) cout << "=";
	else {
		if(a[n - 1] == 'L') {
			if(sz(a) < sz(b)) cout << "<";
			else cout << ">";
		}
		else {
			if(sz(a) < sz(b)) cout << ">";
			else cout << "<";
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
