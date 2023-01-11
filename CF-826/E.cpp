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
    int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<vector<bool>> dp(n + 2, vector<bool>(2, false));
	// [0] piche [1] aage 
	vector<bool> aage(n + 1, false);
	for(int i = 0; i < n; ++i) {
		int ni = i + v[i];
		if(ni < n) {
			dp[ni][0] = dp[ni][0] || ((i == 0 ? (true) : (dp[i - 1][0] || aage[i - 1])));
			
		}
		ni = i - v[i];
		if(ni == 0) dp[i][1] = true, aage[i] = true;
		else if(ni > 0) {
			dp[i][1] = dp[i][1] || dp[ni - 1][0] || aage[ni - 1];
			aage[i] = aage[i] || dp[i][1];
		}
	}
	if(aage[n - 1] || dp[n - 1][1] || dp[n - 1][0]) cout << "YES";
	else cout << "NO";
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
