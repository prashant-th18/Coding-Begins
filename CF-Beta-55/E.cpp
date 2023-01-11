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

// *-> KISS*
int solve() {
    int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	set<array<int, 3>> st;
	for(int i = 0; i < k; ++i) {
		int a, b, c; cin >> a >> b >> c;
		st.insert({a, b, c});
	}
	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
	queue<pair<vector<int>, pair<int, int>>> q; // previous, current, steps
	q.push({{0}, {1, 0}});
	while(!q.empty()) {
		pair<vector<int>, pair<int, int>> p = q.front(); q.pop();
		int previous = p.ff.back(), node = p.ss.ff, steps = p.ss.ss;
		if(node == n) {
			cout << steps << '\n';
			for(int i = 1; i < sz(p.ff); ++i) cout << p.ff[i] << ' ';
			cout << n;
			return 0;
		}
		for(auto& val : v[node]) {
			if(!vis[node][val] && (!st.count({previous, node, val}))) {
				vis[node][val] = true;
				vector<int> here = p.ff; here.push_back(node);
				q.push({here, {val, steps + 1}});
			}
		}
	}
	cout << -1;
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
