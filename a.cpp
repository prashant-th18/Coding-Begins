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

const int M = 1000;
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<int> a(n), c(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
	for(int i = 0; i <= M; ++i) {
		dp[0][i] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		/* if(i == 1) { */
		/* 	for(int j = 1, cc = 0; j <= M; ++j) { */
		/* 		if(a[i - 1] <= j && j <= c[i - 1]) ++cc; */
		/* 		dp[i][j] = cc; */
		/* 	} */
		/* 	continue; */
		/* } */
		for(int j = 1; j <= M; ++j) {
			int elem = j;
			if(elem < a[i - 1]) {
				dp[i][elem] = 0;
			}
			else if(a[i - 1] <= elem && elem <= c[i - 1]) {
				dp[i][elem] = dp[i][elem - 1] + dp[i - 1][elem];
			}
			else {
				dp[i][elem] = dp[i][elem - 1];
			}
		}
	}
	cout << dp[n][M];
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