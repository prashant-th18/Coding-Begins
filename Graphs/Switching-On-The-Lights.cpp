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

int n, m;
vector<vector<vector<pll>>> v;
vector<vector<bool>> vis, toggle;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// *-> KISS*
int solve() {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	cin >> n >> m;
	v.assign(n + 1, vector<vector<pll>>(n + 1, vector<pll>()));
	vis.assign(n + 1, vector<bool>(n + 1, false));
	toggle = vis;
	for(int i = 0; i < m; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		v[a][b].push_back(pll(c, d));
	}
	vis[1][1] = true; toggle[1][1] = true;
	queue<pll> q;
	q.push({1, 1});
	while(!q.empty()) {
		pll top = q.front(); q.pop();
		for(auto& [a, b] : v[top.ff][top.ss]) {
			if(vis[a][b]) continue;
			toggle[a][b] = true;
			for(int i = 0; i < 4; ++i) {
				int na = a + dx[i], nb = b + dy[i];
				if(na >= 1 && nb >= 1 && na <= n && nb <= n && vis[na][nb]) {
					q.push({a, b});
					vis[a][b] = true;
					break;
				}
			}
		}
		for(int i = 0; i < 4; ++i) {
			int ni = top.ff + dx[i], nj = top.ss + dy[i];
			if(ni >= 1 && nj >= 1 && ni <= n && nj <= n && !vis[ni][nj] && toggle[ni][nj]) {
				vis[ni][nj] = true;
				q.push({ni, nj});
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) ans += toggle[i][j];
	cout << ans;
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
