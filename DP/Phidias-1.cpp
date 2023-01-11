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
    int w, h; cin >> w >> h;
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(2, 0));
	for(int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
	}
	vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0));
	// dp[i][j] -> minimal residual in rectangular slab of "i" X "j"
	for(int i = 1; i <= w; ++i) for(int j = 1; j <= h; ++j) dp[i][j] = i * j;
	for(int i = 0; i < n; ++i) {
		dp[v[i][0]][v[i][1]] = 0;
	}
	for(int i = 1; i <= w; ++i) {
		for(int j = 1; j <= h; ++j) {
			// Keep width same
			for(int x = 1; x < j; ++x) {
				dp[i][j] = min(dp[i][j], dp[i][x] + dp[i][j - x]);
			}
			// Keep Height Same
			for(int x = 1; x < i; ++x) {
				dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j]);
			}
		}
	}
	cout << dp[w][h];
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
