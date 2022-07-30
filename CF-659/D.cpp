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
    int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int op = 0;
	for(int j = 30; j >= 0 && (op == 0); --j) {
		int x = 0, y = 0;
		for(int i = 0; i < n; ++i) {
			x += ((v[i] >> j) & 1);
			y += (((v[i] >> j) & 1) == 0);
		}
		if(x % 2 == 0) continue;
		else {
			if(x % 4 == 3 && y % 2 == 0) op = 2;
			else op = 1;
		}
	}
	if (op == 0) {
		cout << "DRAW";
	}
	else if(op == 1) cout << "WIN";
	else cout << "LOSE";
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
