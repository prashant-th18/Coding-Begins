#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 998244353;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

using ll = long long;
const int N = 300 * 300 + 1;
vector<vector<int>> dp;
int add(int a, int b) {
	return ((ll)a + (ll)b) % MOD;
}
// *-> KISS*
int solve() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
    dp.assign(2, vector<int>(2 * N + 1, 0));
	
	dp[0][v[1] + N] = 1;
	for(int i = 3; i <= n; ++i) {
		
		for(int j = -N; j <= N; ++j) {
			dp[i % 2][j + N] = 0;
		}
		
		for(int j = -N; j <= N; ++j) {
			
			int curr = v[i - 1];
			// + K
			int h1 = j - curr;
			// I want to make "i" -> j
			
			if(h1 + N >= 0 && h1 + N <= 2 * N) {
				dp[i % 2][j + N] = add(dp[i % 2][j + N], dp[(i - 1) % 2][h1 + N]);
			}
			
			// -K
			int h2 = curr - j;
			if(h2 + N >= 0 && h2 + N <= 2 * N) {
				if(h1 == 0 && h2 == 0) {}
				else {
					dp[i % 2][j + N] = add(dp[i % 2][j + N], dp[(i - 1) % 2][h2 + N]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = -N; i <= N; ++i) {
		ans = add(ans, dp[n % 2][i + N]);
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