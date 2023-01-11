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

void dfs(int node, vector<int>& order, vector<vector<int>>& v, vector<bool>& vis) {
	vis[node] = true;
	order.push_back(node);
	for(auto val : v[node]) {
		if(!vis[val]) {
			dfs(val, order, v, vis);
		}
	}
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> order;
	vector<bool> vis(n + 1, false);
	dfs(1, order, v, vis);
	sort(all(order));
	vector<ll> dp1(n + 1, (ll)1e18);
	for(int i = 1; i <= n; ++i) {
		auto it = lower_bound(all(order), i);
		if(it != order.end()) {
			ll val = *it;
			dp1[i] = min(dp1[i], (val - i) * (val - i));
		}
		if(it != order.begin()) {
			--it;
			ll val = *it;
			dp1[i] = min(dp1[i], (val - i) * (val - i));
		}
	}
	order.clear();
	vis.assign(n + 1, false);
	dfs(n, order, v, vis);
	sort(all(order));
	vector<ll> dp2(n + 1, (ll)1e18);
	for(int i = n; i >= 1; --i) {
		auto it = lower_bound(all(order), i);
		if(it != order.end()) {
			ll val = *it;
			dp2[i] = (val - i) * (val - i);
		}
		if(it != order.begin()) {
			--it;
			ll val = *it;
			dp2[i] = min(dp2[i], (val - i) * (val - i));
		}
	}
	vis.assign(n + 1, false);
	/* debug("OK"); */
	ll ans = LLONG_MAX;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			order.clear();
			dfs(i, order, v, vis);
			ll minn = 1e18, maxx = 1e18;
			for(auto val : order) {
				minn = min(minn, dp1[val]);
				maxx = min(maxx, dp2[val]);
			}
			ans = min(ans, minn + maxx);
		}
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
