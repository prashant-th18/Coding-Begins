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
    int n, m; cin >> n >> m;
	vector<int> v(n);
	vector<int> cnt(m);
	for(int i = 0; i < n; ++i) cin >> v[i], v[i] %= m, cnt[v[i]]++;
	vector<vector<bool>> dp(m + 1, vector<bool>(m + 1, false));
	for(int i = 0; i < m; ++i) {
		int x = i, y = cnt[i];
		int sum = 0;
		int c = 0;
		while(c < y) {
			sum += x;
			sum %= m;
			++c;
			dp[x][sum] = true;
		}
	}
	if(cnt[0] != 0) {
		cout << "YES"; return 0;
	}
	for(int i = 2; i <= m; ++i) {
		vector<bool> here(m + 1, false);
		for(int j = 0; j <= m; ++j) {
			if(dp[i - 1][j]) here[j] = true;
			for(int k = 0; k < m + 1; ++k) {
				if(dp[i][k]) {
					int pre = (j - k + m) % m;
					if(dp[i - 1][pre]) here[j] = true;
				}
			}
		}
		for(int j = 0; j <= m; ++j) {
			if(here[j]) dp[i][j] = true;
		}
	}
	cout << (dp[m][0] ? "YES" : "NO");
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
