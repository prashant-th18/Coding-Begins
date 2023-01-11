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

using pll = pair<ll, ll>;
// *-> KISS*
int solve() {
    ll n, k; cin >> n >> k;
    vector<pll> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].ff;
    for(int i = 0; i < n; ++i) cin >> v[i].ss;
    	
    sort(all(v));
	ll blow = k;
	bool flag = true;
	for(int i = 0; i < n; ++i) {
		// cout << i << ' ' << k << ' ' << blow << endl;
		ll nh = v[i].ff - blow;
		if(nh <= 0) continue;
		
		k -= v[i].ss;
		if(k <= 0) {
			flag = false; break;
		}
		
		if(nh - k <= 0) {
			blow += k;
			continue;
		}
		
		// k      nh
		ll l = 1, h = (k / v[i].ss);
		ll ans = -1;
		while(l <= h) {
			ll mid = (l + h) >> 1;
			if(k - (mid - 1) * v[i].ss <= 0) {
				h = mid - 1; continue;
			}
			
			ll temp = nh - mid * k + (mid * (mid - 1) / 2 * v[i].ss);
			if(temp <= 0) {
				ans = mid;
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if(ans == -1) {
			flag = false; break;
		}
		else {
			blow += (ans * k - (ans * (ans - 1) / 2) * v[i].ss);
			k = k - (ans - 1) * v[i].ss;
		}
	}
	if(flag) cout << "YES";
	else cout << "NO";
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