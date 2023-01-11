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
vector<bool> vis;
vector<bool> col;
void dfs(int node, bool color) {
	vis[node] = true;
	col[node] = color;
	for(int& val : v[node]) {
		if(!vis[val]) {
			dfs(val, !color);
		}
	}
}
// *-> KISS*
int solve() {
    cin >> n >> m;
	v.assign(n + 1, vector<int>());
	vis.assign(n + 1, false);
	col.assign(n + 1, false);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, false);
	int c0 = 0, c1 = 0;
	for(int i = 1; i <= n; ++i) {
		c0 += col[i] == false;
		c1 += col[i] == true;
	}
	assert(min(c0, c1) <= n / 2);
	if(c0 < c1) {
		cout << c0 << '\n';
		for(int i = 1; i <= n; ++i) {
			if(col[i] == false) cout << i << ' ';
		}
	}
	else {
		cout << c1 << '\n';
		for(int i = 1; i <= n; ++i) {
			if(col[i]) cout << i << ' ';
		}
	}
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
