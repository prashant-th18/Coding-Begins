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
vector<vector<int>> v;
vector<int> in, dp, par;
// *-> KISS*
int solve() {
    int m; cin >> n >> m;
	v.assign(n + 1, vector<int>());
	in.assign(n + 1, 0);
	dp.assign(n + 1, INT_MIN);
	par.assign(n + 1, -1);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		in[b]++;
		v[a].push_back(b);
	}
	
	vector<int> order;
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		if(in[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int t = q.front(); q.pop();
		order.push_back(t);
		
		for(auto val : v[t]) {
			--in[val];
			if(in[val] == 0) q.push(val);
		}
	}
	
	dp[n] = 1;
	par[n] = -1;
	for(int i = sz(order) - 1; i >= 0; --i) {
		int t = order[i];
		for(auto val : v[t]) {
			if(dp[val] + 1 > dp[t]) {
				dp[t] = dp[val] + 1;
				par[t] = val;
			}
		}
	}
	
	if(dp[1] < 0) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << dp[1] << '\n';
		int node = 1;
		vector<int> ans;
		while(node != -1) {
			ans.push_back(node);
			node = par[node];
		}
		for(auto val : ans) cout << val << ' ';
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
