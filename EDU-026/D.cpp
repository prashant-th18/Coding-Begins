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

const int maxx = 3600;
// *-> KISS*
int solve() {
    ll n, k; cin >> n >> k;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(k + 1, vector<ll>(maxx + 1, 0)));
	// dp[i][j][k] ->
	// For first i numbers, If I choose a subset of size "j" from them, and that subset contains 
	// power of 2 = k, then what is the maximum power of 5, I can get.
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= k; ++j) {
			int p2 = 0, p5 = 0;
			ll e = v[i - 1];
			while(e % 2 == 0) e /= 2, ++p2;
			while(e % 5 == 0) e /= 5, ++p5;
			cerr << p2 << ' ' << p5 << endl;
			for(int l = 0; l <= maxx; ++l) {
				// Not considered
				dp[i % 2][j][l] = max(dp[i % 2][j][l], dp[(i - 1) % 2][j][l]);
				// Considered
				if(j == 1 && l == p2) dp[i % 2][j][l] = max(dp[i % 2][j][l], (ll)p5);
				if(j != 1 && l >= p2) {
					dp[i % 2][j][l] = max(dp[i % 2][j][l], p5 + dp[(i - 1) % 2][j - 1][l - p2]);
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= maxx; ++i) {
		ans = max(ans, min((ll)i, dp[n % 2][k][i]));
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
