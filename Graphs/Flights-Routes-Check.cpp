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
vector<vector<int>> v, t;
vector<bool> vis;
vector<int> order, cc;
void dfs1(int node) {
	vis[node] = true;
	for(const auto& val : v[node]) {
		if(!vis[val]) dfs1(val);
	}
	order.push_back(node);
}
void dfs2(int node) {
	vis[node] = true;
	cc.push_back(node);
	for(int& val : t[node]) {
		if(!vis[val]) dfs2(val);
	}
}
// *-> KISS*
int solve() {
    cin >> n >> m;
	v.assign(n + 1, vector<int>());
	t = v;
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		t[b].push_back(a);
	}
	vis.assign(n + 1, false);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs1(i);
		}
	}
	reverse(all(order));
	vis.assign(n + 1, false);
	vector<vector<int>> scc;
	for(int i = 0; i < sz(order); ++i) {
		if(!vis[order[i]]) {
			dfs2(order[i]);
			scc.push_back(cc);
			cc.clear();
		}
	}
	if(sz(scc) == 1) cout << "YES";
	else {
		cout << "NO\n";
		int x = scc[0][0], y = scc[1][0];
		vis.assign(n + 1, false);
		dfs1(x);
		if(vis[y]) cout << y << ' ' << x;
		else cout << x << ' ' << y;
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
