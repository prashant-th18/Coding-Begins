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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    
    ll ans = accumulate(all(v), 0LL);
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			if(n == 2) {
				ans = max(ans, 2 * abs(v[0] - v[1]));
			}
			else {
				ans = max(ans, v[i] * n);
			}
		}
		else if(i == n - 1) {
			if(n == 2) {
				ans = max(ans, 2 * abs(v[0] - v[1]));
			}
			else {
				ans = max(ans, v[i] * n);
			}
		}
		else {
			if(n == 3) {
				ll op1 = abs(v[0] - v[i]);
				op1 *= n;
				ll op2 = abs(v[i] - v[n - 1]);
				op2 *= n;
				ans = max(ans, max(op1, op2));
			}
			else {
				ans = max(ans, v[i] * n);
			}
		}
	}
	cout << ans;
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