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
string s;
vector<int> level;
vector<vector<int>> lca;
vector<vector<int>> dp, LCA;
vector<vector<int>> v;
void dfs(int node, int par, int lvl = 0) {
	level[node] = lvl;
	lca[node][0] = par;
	for(const auto& val : v[node]) {
		if(val != par) {
			dfs(val, node, lvl + 1);
		}
	}
}
void init() {
	dfs(1, -1);
	for(int j = 1; j < 15; ++j) {
		for(int i = 1; i <= n; ++i) {
			int p = lca[i][j - 1];
			if(p != -1) lca[i][j] = lca[p][j - 1];
		}
	}
}
int myLCA(int a, int b) {
	if(level[b] < level[a]) swap(a, b);
	
	int d = level[b] - level[a];
	
	while(d > 0) {
		int p = __lg(d);
		b = lca[b][p];
		
		d -= (1 << p);
	}
	
	if(a == b) return a;
	
	for(int i = 15; i >= 0; --i) {
		if((lca[a][i] != -1) && (lca[a][i] != lca[b][i])) {
			a = lca[a][i], b = lca[b][i];
		}
	}
	
	return lca[a][0];
}
int lowest(int si, int ei) {
	return LCA[si][ei];
}
int get(int si, int ei) {
	if(dp[si][ei] != -1) return dp[si][ei];
	
	// Case
	if(lca[si][0] == ei || lca[ei][0] == si) {
		return dp[si][ei] = max(1, 2 * (int)(s[si] == s[ei]));
	}
	
	int l = lowest(si, ei);
	
	if(l != si && l != ei) {
		return dp[si][ei] = max(2 * (s[si] == s[ei]) + get(lca[si][0], lca[ei][0]), max(get(lca[si][0], ei), get(si, lca[ei][0])));
	}
	
	if(l == si) {
		int d = level[ei] - level[si] - 1;
	
		int temp = ei;
		while(d > 0) {
			int p = __lg(d);
			temp = lca[temp][p];
			
			d -= (1 << p);
		}
		
		dp[si][ei] = max(2 * (s[si] == s[ei]) + get(temp, lca[ei][0]),
			max(get(temp, ei), get(si, lca[ei][0])));
		
		return dp[si][ei];
	}
	else {
	
		int d = level[si] - level[ei] - 1;
	
		int temp = si;
		while(d > 0) {
			int p = __lg(d);
			temp = lca[temp][p];
			
			d -= (1 << p);
		}
		
		dp[si][ei] = max(2 * (s[si] == s[ei]) + get(lca[si][0], temp),
			max(get(lca[si][0], ei), get(si, temp)));
		
		return dp[si][ei];
	}
	
}
// *-> KISS*
int solve() {
    cin >> n;
    cin >> s;
    s = "." + s;
    level.assign(n + 1, 0);
    lca.assign(n + 1, vector<int>(32, -1));
    dp.assign(n + 1, vector<int>(n + 1, -1));
    LCA = dp;
    v.assign(n + 1, vector<int>());
    for(int i = 0; i < n - 1; ++i) {
    	int a, b; cin >> a >> b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    }
    init();
    int ans = 1;
    for(int i = 1; i <= n; ++i) dp[i][i] = 1;
    for(int i = 1; i <= n; ++i) {
    	for(int j = 1; j <= n; ++j) {
    		LCA[i][j] = myLCA(i, j);
    	}
    }
    for(int i = 1; i <= n; ++i) {
    	for(int j = 1; j <= n; ++j) {
    		if(i == j) continue;
    		else {
    			dp[i][j] = get(i, j);
    		}
    		ans = max(ans, dp[i][j]);
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
