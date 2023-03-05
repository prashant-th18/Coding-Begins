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
const int maxx = 1000000000;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tot = 0;
// *-> KISS*
int solve() {
    int n; cin >> n;
	tot += n;
	assert(1 <= n && n <= (ll)1e6);
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		assert(-maxx <= v[i] && v[i] <= maxx);
	}
	vector<ll> dp(n, LLONG_MIN);
	dp[n - 1] = v[n - 1];
	for(int i = n - 2; i >= 0; --i) {
		for(int j = 0; j < 28; ++j) {
			int ni = i + (1 << j);
			if(ni < n) {
				dp[i] = max(dp[i], v[i] + dp[ni]);
			}
		}
	}
	cout << dp[0];
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
        if (solve()) {
            break;
        }
        cout << '\n';
    }
	assert(tot <= (ll)1e6);
	return 0;
}
// -> Keep It Simple Stupid!
