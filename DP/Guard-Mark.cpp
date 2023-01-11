#include <cstdint>
#include <cstdio>
#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	using ll = long long;
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
	for(int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
		swap(v[i][0], v[i][2]);
		// Strength, weight, height
	}
	vector<array<ll, 3>> dp(1 << n, {0, 0, 0});
	for(int i = 1; i < (1 << n); ++i) {
		for(int j = 0; j < n; ++j) {
			if(i & (1 << j)) {
				if((i ^ (1 << j)) == 0) {
					dp[i] = max(dp[i], v[j]);
				}
				else {
					array<ll, 3> t = dp[i ^ (1 << j)];
					array<ll, 3> t1 = dp[i ^ (1 << j)];
					array<ll, 3> t2 = t1;
					t1[0] = min(t[0] - v[j][1], v[j][0]);
					t2[0] = min(v[j][0] - t[1], t[0]);
					t1[2] += v[j][2]; t1[1] += v[j][1];
					t2[2] += v[j][2]; t2[1] += v[j][1];
					dp[i] = max({t1, t2, dp[i]});
				}
			}
		}
	}
	ll maxx = -1;
	for(int i = 1; i < (1 << n); ++i) {
		if(dp[i][2] >= h) maxx = max(maxx, dp[i][0]);
	}
	if(maxx != -1) {
		cout << maxx;
	}
	else {
		cout << "Mark is too tall";
	}
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
