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

int n;
vector<vector<int>> dp;
string s, t;
int dfs(int i, int j) {
	if(dp[i][j] != -1) return dp[i][j];
	if(i > j) return 1;

	if(i == j) {
		return dp[i][j] = (s[i] == t[i]);
	}
	char a1 = s[i], a2 = t[i], b1 = s[j], b2 = t[j];
	if(a1 == a2) {
		dp[i][j] = max(dp[i][j], dfs(i + 1, j));
	}
	if(b1 == b2) {
		dp[i][j] = max(dp[i][j], dfs(i, j - 1));
	}
	dp[i][j] = max(dp[i][j], 0);
	return dp[i][j];
}
// *-> KISS*
int solve() {
    cin >> n;
	dp.assign(n + 1, vector<int>(n + 1, -1));
	cin >> s >> t;
	int op = dfs(n - 1, 0);
	assert(op != -1);
	if(op == 0) cout << "NO";
	else cout << "YES";
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
		cout << "Case " << i << ": ";
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
