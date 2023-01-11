// #include <numeric>
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
    for(int i = 0; i < n; ++i) cin >> v[i];
    ll sum = accumulate(all(v), 0LL);
	if(sum % 2 == 0) {
		cout << 0; return 0;
	}
	
	// Either make an even odd 
	// Or make an odd even
	ll op1 = 1e6, op2 = 1e6;
	for(int i = 0; i < n; ++i) {
		if(v[i] % 2 == 0) {
			ll ok = 0;
			while(v[i] % 2 == 0) {
				v[i] >>= 1;
				++ok;
			}
			op1 = min(op1, ok);
		}
		else {
			ll ok = 0;
			while(v[i] & 1) {
				v[i] >>= 1;
				++ok;
			}
			op2 = min(op2, ok);
		}
	}
	cout << min(op1, op2);
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
