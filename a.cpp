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

int n, q;
const int K = 26;
vector<vector<int>> v;
vector<vector<int>> lca;
vector<int> depth;
void dfs(int node, int par, int d = 0) {
    depth[node] = d;
    lca[node][0] = par;
    for(const int& val : v[node]) {
        if(val != par) {
            dfs(val, node, d + 1);
        }
    }
}
void init() {
    depth.assign(n + 1, 0);
    lca.assign(n + 1, vector<int>(K + 1, -1));
    dfs(1, -1);
    for(int i = 1; i <= K; ++i) {
        for(int j = 1; j <= n; ++j) {
            int p = lca[j][i - 1];
            if(p != -1) lca[j][i] = lca[p][i - 1];
        }
    }
}
int get(int node, int d) {
    while(d > 0 && node != -1) {
        int p = __lg(d);
        node = lca[node][p];
    }
    return node;
}
// *-> KISS*
int solve() {
	cin >> n >> q;
    v.assign(n + 1, vector<int>());
    for(int i = 0; i < n - 1; ++i) {
    	int a, b; cin >> a >> b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    }
    init();
    
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