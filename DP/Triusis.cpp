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

const int maxx = 5000;
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(maxx + 1, INT_MAX));
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		ll d, u;
		for(int j = 0; j <= maxx; ++j) {
			if(j == 0) {
				// -m -> +m
				d = -m; u = m;
			}
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
