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

// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans = 1e6;
	for(int i = 1; i <= n; ++i) {
		queue<pll> q;
		vector<int> dist(n + 1, 0);
		vector<bool> vis(n + 1, false);
		q.push({i, -1});
		dist[i] = 0;
		vis[i] = true;
		while(!q.empty()) {
			pll p = q.front(); q.pop();
			int par = p.ss, t = p.ff;
			for(int& val : v[t]) {
				if(!vis[val]) {
					q.push({val, t}); vis[val] = true; dist[val] = dist[t] + 1;
				}
				else if(val != par) {
					ans = min(ans, dist[val] + dist[t] + 1);
				}
			}
		}
	}
	if(ans == (int)1e6) ans = -1;
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
