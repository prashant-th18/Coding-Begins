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
    int x, y, z; cin >> x >> y >> z;
	if(x > 0) {
		if(y > x) cout << x;
		else if(y > 0) {
			if(z > y) cout << -1;
			else {
				int s = 0;
				if(z < 0) s += (-2 * z + x);
				else s = x;
				cout << s;
			}
		}
		else {
			cout << x;
		}
	}
	else {
		// x < 0
		if(y < x) cout << -x;
		else if(y > 0) cout << -x;
		else {
			if(z < y) cout << -1;
			else {
				if(z > 0) cout << 2 * z + (-x);
				else cout << -x;
			}
		}
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
