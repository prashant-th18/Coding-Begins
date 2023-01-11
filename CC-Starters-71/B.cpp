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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for(int i = 1; i <= n; ++i) {
    	char ch = s[i - 1];
    	if(ch == '0') {
    		dp[i][1] = dp[i - 1][1];
    		dp[i][0] = 1 + dp[i - 1][1];
    	}
    	else {
    		dp[i][0] = dp[i - 1][0];
    		dp[i][1] = 1 + dp[i - 1][0];
    	}
    }
    vector<int> pre(n + 1);
    for(int i = 2; i <= n; ++i) {
    	pre[i] = pre[i - 1] + (s[i - 1] != s[i - 2]);
    }
    int ans = INT_MAX;
    for(int i = k; i <= n; ++i) {
    	int dif = pre[i] - pre[i - k + 1];
    	if(s[i - 1] == '0') ++dif;
    	ans = min(ans, dp[i][0] - dp[i - k][dif % 2]);
    }
    cout << ans;
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