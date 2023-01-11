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

int n, q;
vector<vector<pll>> v;
vector<bool> vis;
vector<int> col, order;
bool dfs(int node, int color) {
	vis[node] = true;
	col[node] = color;
	order.push_back(node);
	for(auto& [x, val] : v[node]) {
		if(!vis[val]) {
			if(x == 1) {
				if(!dfs(val, 1 - color)) {
					return false;
				}
			}
			else {
				if(!dfs(val, color)) return false;
			}
		}
		else {
			if(x == 1) {
				if(col[val] == color) return false;
			}
			else {
				if(col[val] != color) return false;
			}
		}
	}
	return true;
}
// *-> KISS*
int solve() {
	order.clear();
    cin >> n >> q;
	v.assign(n + 1, vector<pll>());
	vis.assign(n + 1, false);
	col.assign(n + 1, 0);
	for(int i = 0; i < q; ++i) {
		int t; cin >> t;
		int a, b; cin >> a >> b;
		v[a].push_back(pll(t, b));
		v[b].push_back(pll(t, a));
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			if(!dfs(i, 0)) {
				cout << -1; return 0;
			}
			int c1 = 0, c2 = 0;
			for(auto val : order) {
				c1 += col[val] == 1;
				c2 += col[val] == 0;
			}
			ans += max(c1, c2);
			order.clear();
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
