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
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	vector<ll> b(n + 1);
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			b[i] = b[i + 1] = a[i];
			// b[i + 1] should be multiple of a[i] now
		}
		else {
			// Assume b[i] = a[i]
			// Then, how can it fail the condition
			// b[i] , b[i + 1] = a[i]
			// but b[i] was earlier evaluated
			// So, keep b[i] in such a way that gcd(b[i], b[i + 1]) = a[i] and b[i] = a[i - 1] * k
			// so, t = lcm(a[i], b[i])
			// b[i] = t, b[i + 1] = a[i]
			ll t = lcm(a[i], b[i]);
			b[i] = t;
			b[i + 1] = a[i];
		}
	}
	for(int i = 0; i < n; ++i) {
		if(gcd(b[i], b[i + 1]) != a[i]) {
			cout << "No"; return 0;
		}
	}
	cout << "Yes";
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
