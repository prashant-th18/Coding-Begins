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
using pll = pair<ll, ll>;
const int inf = (int)1e9;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int dist(pll a, pll b) {
	ll d1 = a.ff - b.ff, d2 = a.ss - b.ss;
	return d1 * d1 + d2 * d2;
}
// *-> KISS*
int solve() {
	int xs, ys; cin >> xs >> ys;
    int n; cin >> n;
	vector<pll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].ff >> v[i].ss;
	vector<int> dp(1 << n, inf);
	// dp[i] -> Consider the subset given by "i", then what is the minimum time taken to have some valid
	// configuration and then return back to "0";
	dp[0] = 0;
	for(int mask = 1; mask < (1 << n); ++mask) {
		for(int i = 0; i < n; ++i) {
			if((mask & (1 << i)) == 0) continue;
			int sub = mask ^ (1 << i);

			dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + 2 * dist({xs, ys}, v[i]));
			for(int j = 0; j < n; ++j) {
				if((sub & (1 << j)) == 0) continue;

				dp[mask] = min(dp[mask], dp[mask ^ (1 << i) ^ (1 << j)] + dist({xs, ys}, v[i]) + 
						dist(v[i], v[j]) + dist({xs, ys}, v[j]));
			}
		}
	}
	cout << dp[(1 << n) - 1];
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
