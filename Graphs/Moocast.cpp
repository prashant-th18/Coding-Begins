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

// *-> KISS*
int solve() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    int n; cin >> n;
	vector<pll> v(n);
	vector<ll> c(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i].ff >> v[i].ss;
		cin >> c[i];
	}
	vector<vector<int>> reach(n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			ll d1 = (v[i].ff - v[j].ff), d2 = (v[i].ss - v[j].ss);
			d1 *= d1; d2 *= d2;
			if(d1 + d2 <= c[i] * c[i]) reach[i].push_back(j);
		}
	}
	int ans = 1;
	for(int i = 0; i < n; ++i) {
		vector<bool> vis(n, false);
		queue<int> q;
		int cc = 0;
		for(int j = 0; j < sz(reach[i]); ++j) vis[reach[i][j]] = true, q.push(reach[i][j]), ++cc;
		while(!q.empty()) {
			int node = q.front(); q.pop();
			for(int j = 0; j < sz(reach[node]); ++j) {
				if(!vis[reach[node][j]]) {
					vis[reach[node][j]] = true;
					++cc;
					q.push(reach[node][j]);
				}
			}
		}
		ans = max(ans, cc);
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
