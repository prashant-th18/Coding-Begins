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

int n, m;
vector<vector<int>> v;
vector<ll> dp;
vector<bool> vis;
ll add(ll a, ll b) {
	return min((ll)1e6, a + b);
}
ll ans = 1;
void dfs(int node) {
	vis[node] = true;
	vector<int> order;
	for(auto& val : v[node]) {
		if(!vis[val]) {
			dfs(val);
			order.push_back(val);
			dp[node] = add(dp[node], dp[val]);
			if(dp[node] == (ll)1e6) {
				ans = 1e6;
				return;
			}
		}
	}
	for(int val : order) {
		
	}
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n + 1, vector<int>());
    dp.assign(n + 1, 1);
    vis.assign(n + 1, false);
    dfs(1);
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