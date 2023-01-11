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

const int N = 1000;
// *-> KISS*
int solve() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
    ll n, m, c; cin >> n >> m >> c;
	vector<ll> value(n + 1);
	for(int i = 0; i < n; ++i) cin >> value[i + 1];
	vector<vector<int>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		int uu, vv; cin >> uu >> vv;
		v[uu].push_back(vv);
	}
	ll max_ans = 0;
	vector<vector<ll>> dp(N + 2, vector<ll>(n + 1, -1));
	// dp[i][j] -> Maximum cost I can get, if I travel for exactly "i" days and "end" my trip at city "j"
	dp[0][1] = 0; // Base Case
	for(int i = 0; i <= N; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(dp[i][j] != -1) {
				for(auto& val : v[j]) {
					dp[i + 1][val] = max(dp[i + 1][val], dp[i][j] + value[val]);
				}
			}
		}
		max_ans = max(max_ans, dp[i][1] - c * i * i);
	}
	cout << max_ans;
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
