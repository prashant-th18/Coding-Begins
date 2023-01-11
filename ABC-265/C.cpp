#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int h, w;
vector<string> v;
vector<vector<bool>> vis;
map<char, pair<int, int>> mp;
pair<int, int> ans = {-1, -1};
void dfs(int x, int y) {
	vis[x][y] = true;
	int ni = x + mp[v[x][y]].ff, nj = y + mp[v[x][y]].ss;
	if(ni < 0 || ni >= h || nj < 0 || nj >= w) {
		ans = pair<int, int>(x, y); return;
	}
	if(vis[ni][nj]) {
		return;
	}
	dfs(ni, nj);
}
// *-> KISS*
int solve() {
    cin >> h >> w;
	v.assign(h, "");
	for(int i = 0; i < h; ++i) {
		cin >> v[i];
	}
	mp['R'] = pair<int, int>(0, 1);
	mp['U'] = pair<int, int>(-1, 0);
	mp['L'] = pair<int, int>(0, -1);
	mp['D'] = pair<int, int>(1, 0);
	vis.assign(h, vector<bool>(w, false));
	dfs(0, 0);
	if(ans.ff == -1) cout << -1;
	else {
		cout << ans.ff + 1 << ' ' << ans.ss + 1;
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
