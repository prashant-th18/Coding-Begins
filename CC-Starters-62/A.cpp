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
	/* for(ll a = 2; a <= 10; ++a) { */
	/* 	for(ll b = a + 1; b <= 200; ++b) { */
	/* 		// b / a */
	/* 		bool f = false; */
	/* 		for(int i = 0; i < 1000; ++i) { */
	/* 			f |= ((b + i) % (a + i) == 0); */
	/* 		} */
	/* 		if(f) cout << "YES\n"; */
	/* 		else cout << a << ' ' << b << endl; */
	/* 	} */
	/* } */
	ll a, b; cin >> a >> b;
	if(a < b && b < 2 * a) cout << "NO";
	else cout << "YES";
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
