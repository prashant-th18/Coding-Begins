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

const ll INF = (ll)1e15;
// *-> KISS*
int solve() {
    ll n, m, l; cin >> n >> m >> l;
	vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, INF));
	for(int i = 0; i < n; ++i) adj[i + 1][i + 1] = 0;

	for(int i = 0; i < m; ++i) {
		ll a, b, c; cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(adj[i][j] <= l) {
				dp[i][j] = 1;
			}
			if(i == j) dp[i][j] = 0;
		}
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	int q; cin >> q;
	while(q--) {
		int s, t; cin >> s >> t;
		if(dp[s][t] == INF) cout << -1;
		else cout << dp[s][t] - 1;
		cout << '\n';
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
