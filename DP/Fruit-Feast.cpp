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
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
    ll t, a, b;
	cin >> t >> a >> b;
	vector<bool> dp(t + 1, false);
	dp[0] = true;
	for(int i = 0; i <= t; ++i) {
		if(dp[i] && i + a <= t) dp[i + a] = true;
		if(dp[i] && i + b <= t) dp[i + b] = true;
	}
	for(int i = 1; i <= t; ++i) {
		if(dp[i]) dp[i >> 1] = true;
	}
	for(int i = 0; i <= t; ++i) {
		if(dp[i]) {
			if(i + a <= t) dp[i + a] = true;
			if(i + b <= t) dp[i + b] = true;
		}
	}
	for(int i = t; i >= 0; --i) {
		if(dp[i]) {
			cout << i; return 0;
		}
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
