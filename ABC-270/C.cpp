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

int n, x, y;
vector<vector<int>> v;
vector<bool> vis;
vector<int> par;
void dfs(int node) {
	vis[node] = true;
	if(node == y) return;
	for(const auto& val : v[node]) {
		if(!vis[val]) {
			par[val] = node;
			dfs(val);
		}
	}
}
// *-> KISS*
int solve() {
    cin >> n >> x >> y;
	v.assign(n + 1, vector<int>());
	vis.assign(n + 1, false);
	par.assign(n + 1, -1);
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(x);
	vector<int> t;
	int node = y;
	while(node != -1) {
		t.push_back(node);
		node = par[node];
	}
	reverse(all(t));
	for(auto val : t) cout << val << ' ';
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
