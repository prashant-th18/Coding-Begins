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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    ll n, k; cin >> n >> k;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	sort(all(v));
	ll sum = 2 * k;
	vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
	dp[0][0] = true;
	for(int i = 1; i <= n; ++i) {
		for(int s = 0; s <= sum; ++s) {
			if(s == 0) dp[i][s] = true;
			else {
				dp[i][s] = dp[i - 1][s];
				if(v[i - 1] <= s) {
					dp[i][s] = dp[i][s] | dp[i - 1][s - v[i - 1]];
				}
			}
		}
	}
	for(int i = k; i <= 2 * k; ++i) {
		if(dp[n][i]) {
			cout << i; return 0;
		}	
	}
	int in = lower_bound(all(v), 2 * k) - v.begin();
	cout << v[in];
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
