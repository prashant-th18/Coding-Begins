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
    
    vector<vector<int>> suf(n + 1, vector<int>(4, n + 1));
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 0; j <= 3; ++j) {
			if(v[i] == j) suf[i][j] = i;
			else suf[i][j] = suf[i + 1][j];
		}
	}
	
	vector<ll> dp(n + 1, 0);
	// Starting from i, what are the number of subsequences
	// for every j from i to n - 1.
	for(int i = n - 1; i >= 0; --i) {
		if(v[i] == 0) {
			dp[i] = (n - i) + dp[i + 1];
		}
		else if(v[i] == 1) {
			int in = min(suf[i][0], suf[i][2]);
			if(in == n + 1) {
				// No 0 or 2
				dp[i] = (n - i);
			}
			else {
				dp[i] = (in - i) + (n - in) + dp[in];
			}
		}
		else if(v[i] == 2) {
			int in = min(suf[i][0], min(suf[i][1], suf[i][3]));
			if(in == n + 1) dp[i] = n - i;
			else {
				if((v[in] & v[i]) == 0) {
					dp[i] = (n - i) + dp[in];
				}
				else {
					in = min(suf[in + 1][0], suf[in + 1][1]);
					if(in == n + 1) {
						dp[i] = (n - i);
					}
					else {
						dp[i] = (n - i) + dp[in];
					}
				}
			}
		}
		else {
			// v[i] == 3
			int in = min(suf[i][0], min(suf[i][1], suf[i][2]));
			if(in == n + 1) dp[i] = n - i;
			else if(v[in] == 0) {
				dp[i] = (n - i) + dp[in];
			}
			else if(v[in] == 1) {
				int in2 = min(suf[i][0], suf[i][2]);
				if(in2 == n + 1) {
					// No 0 or 2
					dp[i] = (n - i);
				}
				else {
					dp[i] = (in2 - i) + (n - in2) + dp[in2];
				}
			}
			else {
				// v[in] == 2
				int in2 = min(suf[i][0], min(suf[i][1], suf[i][3]));
				if(in2 == n + 1) dp[i] = n - i;
				else {
					if((v[in2] & v[i]) == 0) {
						dp[i] = (n - i) + dp[in2];
					}
					else {
						in2 = min(suf[in2 + 1][0], suf[in2 + 1][1]);
						if(in2 == n + 1) {
							dp[i] = (n - i);
						}
						else {
							dp[i] = (n - i) + dp[in2];
						}
					}
				}
			}
		}
		cout << dp[i] << endl;
	}
	cout << accumulate(all(dp), 0LL);
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
