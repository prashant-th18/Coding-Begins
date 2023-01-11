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
using pll = pair<int, int>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> v;
vector<bool> vis;
vector<pll> c;
int minx, maxx, miny, maxy;
void dfs(int node) {
	vis[node] = true;
	minx = min(minx, c[node].ff);
	maxx = max(maxx, c[node].ff);
	miny = min(miny, c[node].ss);
	maxy = max(maxy, c[node].ss);
	for(const auto& val : v[node]) {
		if(!vis[val]) {
			dfs(val);
		}
	}
}
// *-> KISS*
int solve() {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;
	v.assign(n + 1, vector<int>());
	vis.assign(n + 1, false);
	c.assign(n + 1, pll(0, 0));
	for(int i = 0; i < n; ++i) {
		cin >> c[i + 1].ff >> c[i + 1].ss;
	}
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int minPerimeter = INT_MAX;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			minx = 1e9; maxx = 0, miny = 1e9, maxy = 0;
			dfs(i);
			minPerimeter = min(minPerimeter, 2 * (maxx - minx) + 2 * (maxy - miny));
		}
	}
	cout << minPerimeter;
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
