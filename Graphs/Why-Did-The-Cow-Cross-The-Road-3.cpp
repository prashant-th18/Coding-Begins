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

int n, k, r, cc = 0;
vector<vector<bool>> vis, cow;
vector<vector<set<pll>>> v;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int i, int j) {
	cc += (cow[i][j]);
	vis[i][j] = true;
	for(int kk = 0; kk < 4; ++kk) {
		int ni = i + dx[kk], nj = j + dy[kk];
		if(ni >= 1 && ni <= n && nj >= 1 && nj <= n && !vis[ni][nj]) {
			if(!v[i][j].count({ni, nj})) {
				dfs(ni, nj);
			}
		}
	}
}
// *-> KISS*
int solve() {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
	v.assign(n + 1, vector<set<pll>>(n + 1, set<pll>()));
	vis.assign(n + 1, vector<bool>(n + 1, false));
	cow = vis;
	for(int i = 0; i < r; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		v[a][b].insert({c, d});
		v[c][d].insert({a, b});
	}
	for(int i = 0; i < k; ++i) {
		int a, b; cin >> a >> b;
		cow[a][b] = true;
	}
	vector<ll> components;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(!vis[i][j]) {
				dfs(i, j);
				if(cc != 0) components.push_back(cc);
				cc = 0;
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < sz(components); ++i) {
		for(int j = i + 1; j < sz(components); ++j) {
			ans += components[i] * components[j];
		}
	}
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
