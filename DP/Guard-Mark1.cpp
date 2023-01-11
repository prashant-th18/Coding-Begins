#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
    ll n, h; cin >> n >> h;
	vector<array<ll, 3>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	// Height, Weight, Strength
	vector<ll> dp(1 << n);
	// dp[i] -> 
	// Suppose I take all the cows which are in mask "i", then dp[i] tells me the maximum safety I can get
	dp[0] = MOD;
	for(int i = 1; i < (1 << n); ++i) {
		dp[i] = -MOD;
		for(int j = 0; j < n; ++j) {
			if((i & (1 << j))) {
				// We assume that okay dp[i ^ (1 << j)] gives me the maximum safety, so what If I placed
				// j'th cow on top of that arrangement
				dp[i] = max(dp[i], min(v[j][2], dp[i ^ (1 << j)] - v[j][1]));
			}
		}
	}
	ll maxx = -1;
	for(int i = 1; i < (1 << n); ++i) {
		ll sum = 0;
		for(int j = 0; j < n; ++j) {
			if((i & (1 << j))) sum += v[j][0];
		}
		if(sum >= h) {
			maxx = max(maxx, dp[i]);
		}
	}
	if(maxx == -1) cout << "Mark is too tall";
	else cout << maxx;
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
