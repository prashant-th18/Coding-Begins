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
const int inf = (int)1e9;

// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m, '.'));
	queue<pll> q; pll pos;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<vector<int>> dis(n, vector<int>(m, inf)), d(n, vector<int>(m, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if(v[i][j] == 'M') q.push({i, j}), vis[i][j] = true, dis[i][j] = 0;
			else if(v[i][j] == 'A') pos = {i, j};
		}
	}
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	auto valid = [&](int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < m && v[i][j] != '#';
	};
	while(!q.empty()) {
		pll p = q.front();
		q.pop();
		for(int k = 0; k < 4; ++k) {
			int ni = p.ff + dx[k], nj = p.ss + dy[k];
			if(valid(ni, nj) && !vis[ni][nj]) {
				vis[ni][nj] = true;
				dis[ni][nj] = 1 + dis[p.ff][p.ss];
				q.push({ni, nj});
			}
		}
	}
	vis.assign(n, vector<bool>(m, false));
	vector<vector<pll>> par(n, vector<pll>(m, {-1, -1}));
	q.push(pos); vis[pos.ff][pos.ss] = true; d[pos.ff][pos.ss] = 0;
	deque<pll> ans;
	auto get = [&](pll a, pll b) {
		if(a.ff + 1 == b.ff) return "D";
		if(a.ff - 1 == b.ff) return "U";
		if(a.ss + 1 == b.ss) return "R";
		return "L";
	};
	while(!q.empty()) {
		pll p = q.front(); q.pop();
		if(p.ff == n - 1 || p.ff == 0 || p.ss == 0 || p.ss == m - 1) {
			cout << "YES\n";
			pll pre = p;
			while(pre.ff != -1) {
				ans.push_front(pre);
				pre = par[pre.ff][pre.ss];
			}
			cout << sz(ans) - 1 << '\n';
			string res = "";
			for(int i = 1; i < sz(ans); ++i) {
				res += get(ans[i - 1], ans[i]);
			}
			cout << res;
			return 0;
		}
		for(int k = 0; k < 4; ++k) {
			int ni = p.ff + dx[k], nj = p.ss + dy[k];
			int nd = d[p.ff][p.ss] + 1;
			if(valid(ni, nj) && !vis[ni][nj] && nd < dis[ni][nj]) {
				par[ni][nj] = p;
				vis[ni][nj] = true;
				d[ni][nj] = nd;
				q.push({ni, nj});
			}
		}
	}
	cout << "NO";
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
