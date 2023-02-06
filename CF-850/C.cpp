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
    vector<ll> v(n);
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    	sum += v[i];
    }
    ll ans = sum;
    sort(all(v));
    ll cnt = 1;
    sum = 0;
    for(int i = 0; i < n; ++i) {
    	// WE want to make this equal to "cnt"
    	if(v[i] - cnt >= 0) {
    		sum += v[i] - cnt;
    		++cnt;
    	}
    }
    cout << min(ans, sum);
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    cin >> TET;
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