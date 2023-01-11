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
	/* for(int i = 100; i <= 500; ++i) { */
	/* 	int num = sqrt(i); */
	/* 	if(i % num == 0) cout << i << '\n'; */
	/* } */
	// 3-3 ko hi krr rha
	ll l, r; cin >> l >> r;
	vector<ll> v;
	auto fun = [&](ll n) {
		if(n == 0) return 0LL;
		// [1 .. n]
		ll num = (ll)sqrtl(n);
		ll pre = num;
		ll ans = 0;
		ans += (num - 1) * 3;
		num *= num;

		ll how = 0;
		for(int j = 0; ; ++j) {
			if(num + (j * pre) <= n) {
				how = j + 1;
			}
			else break;
		}
		ans += how;
		return ans;
	};
	cout << fun(r) - fun(l - 1);
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
