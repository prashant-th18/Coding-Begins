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
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
    ll n, l; cin >> n >> l;
	vector<ll> d(n);
	vector<vector<ll>> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
		ll ss; cin >> ss;
		vector<ll> v(ss);
		for(int j = 0; j < ss; ++j) cin >> v[j];
		s[i] = v;
	}
	int ans = 40;
	vector<ll> dp(1 << n, -1);
	// dp[i] -> Maximum time achievable from subset "i"
	// Base Case
	dp[0] = 0;
	for(int i = 0; i < (1 << n); ++i) {

		if(dp[i] >= l) {
			ans = min(ans, __builtin_popcount(i));
		}
		for(int j = 0; j < n; ++j) {
			if(i & (1 << j)) continue;

			// Try adding "j"
			if(dp[i] == -1) continue;
			
			int nmask = i | (1 << j);

			int index = (upper_bound(all(s[j]), dp[i]) - begin(s[j])) - 1;
			if(index >= 0) {
				dp[nmask] = max(dp[nmask], d[j] + s[j][index]);
			}
		}
	}
	if(ans == 40) ans = -1;
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
