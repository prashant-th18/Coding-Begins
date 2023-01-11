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

ll fun(ll minn, ll a) {
	if(a < minn) return 0;
	ll h1 = a / 2, h2 = a - h1;
	if(h1 >= minn) {
		h2 += (h1 - minn + 1);
	}
	return 1 + fun(minn, h2);
}
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	ll ans = 0;
	ll minn = 2 * v[0];
	for(int i = 1; i < n; ++i) {
		if(v[i] < minn) continue;
		else {
			ans += fun(minn, v[i]);
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
