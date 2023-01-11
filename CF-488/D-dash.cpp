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
using pll = pair<ll, ll>;

int n, m;
vector<pll> a, b;
vector<vector<bool>> dp;
vector<vector<bool>> vis;
set<int> ans;
pair<set<int>, int> get(pll a, pll b) {
	set<int> st;
	st.insert(a.ff); st.insert(a.ss); st.insert(b.ss); st.insert(b.ff);
	if(sz(st) != 3) return {st, -1};
	int cm = -1;
	if(a.ff == b.ff || a.ff == b.ss) cm = a.ff;
	if(a.ss == b.ff || a.ss == b.ss) cm = a.ss;
	return {st, cm};
}
bool dfs(int i, int j) {
	if(vis[i][j]) return dp[i][j];
	
	vis[i][j] = true;

	
}
// *-> KISS*
int solve() {
    cin >> n;
	a.assign(n, {0, 0});
	b.assign(m, {0, 0});
	for(int i = 0; i < n; ++i) cin >> a[i].ff >> a[i].ss;
	for(int i = 0; i < m; ++i) cin >> b[i].ff >> b[i].ss;
	dp.assign(n, vector<bool>(m, false)); // Checks validity of [i][j]
	vis.assign(n, vector<bool>(m, false));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			dfs(i, j);
		}
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
