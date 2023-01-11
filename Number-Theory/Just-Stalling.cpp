	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<ll> h(n), s(n);
	for(int i = 0; i < n; ++i) cin >> h[i];
	for(int i = 0; i < n; ++i) cin >> s[i];
	sort(h.begin(), h.end());
	sort(s.begin(), s.end());
	ll ans = 1;
	for(int i = n - 1; i >= 0; --i) {
		int cnt = 0;
		for(int j = 0; j < n; ++j) cnt += (h[i] <= s[j]);
		cnt -= (n - 1 - i);
		ans *= cnt;
	}
	cout << ans;
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
