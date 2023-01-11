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
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll n, m, k;
vector<vector<pll>> v;
vector<ll> c;
vector<bool> vis;
void dfs(int node) {
	vis[node] = true;
	for(const auto& [val, w] : v[node]) {
		if(!vis[val] && w == 0) dfs(val);
	}
}
// *-> KISS*
int solve() {
    cin >> n >> m >> k;
	c.assign(k, 0);
	vis.assign(n + 1, false);
	for(int i = 0; i < k; ++i) cin >> c[i];
	v.assign(n + 1, vector<pll>());
	vector<array<ll, 3>> edges(m);
	for(int i = 0; i < m; ++i) {
		ll x, y, z; cin >> x >> y >> z;
		edges[i] = {x, y, z};
		v[x].push_back(pll(y, z));
		v[y].push_back(pll(x, z));
	}
	vector<vector<ll>> dp(k + 1, vector<ll>(k + 1, 1e12));
	vector<ll> pos(n + 1, 0);
	ll sum = 0;
	for(int i = 0; i < k; ++i) {
		// sum + 1 .. sum + c[i]
		dfs(sum + 1);
		for(int j = sum + 1; j <= sum + c[i]; ++j) {
			if(!vis[j]) {
				cout << "No"; return 0;
			}
			pos[j] = i + 1;
		}
		dp[i + 1][i + 1] = 0;
		vis.assign(n + 1, false);
		sum += c[i];
	}
	cout << "Yes\n";
	for(int i = 0; i < m; ++i) {
		array<ll, 3> f = edges[i];
		ll x = pos[f[0]], y = pos[f[1]], z = f[2];
		if(x != y) {
			dp[x][y] = min(dp[x][y], z);
			dp[y][x] = min(dp[y][x], z);
		}
	}
	for(int x = 1; x <= k; ++x) {
		for(int i = 1; i <= k; ++i) {
			for(int j = 1; j <= k; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][x] + dp[x][j]);
			}
		}
	}
	for(int i = 1; i <= k; ++i) for(int j = 1; j <= k; ++j) if(dp[i][j] >= 1e12) dp[i][j] = -1;
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) cout << dp[i][j] << ' ';
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
