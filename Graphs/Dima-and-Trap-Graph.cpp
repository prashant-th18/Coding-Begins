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
vector<bool> vis;
vector<vector<array<int, 3>>> v;
bool dfs(int node, int l, int r) {
	if(node == n) return true;
	vis[node] = true;
	for(auto& val : v[node]) {
		if(vis[val[0]]) continue;
		int nl = val[1], nr = val[2], ng = val[0];
		if(nl <= l && r <= nr) {
			if(dfs(ng, l, r)) return true;
		}
	}
	return false;
}
// *-> KISS*
int solve() {
    // (l, r), node
   	int m; cin >> n >> m;
   	v.assign(n + 1, vector<array<int, 3>>());
   	for(int i = 0; i < m; ++i) {
   		int a, b, l, r; cin >> a >> b >> l >> r;
   		v[a].push_back({b, l, r});
   		v[b].push_back({a, l, r});
   	}
   	
   	auto ok = [&](int l, int r) -> bool {
   		vis.assign(n + 1, false);
   		return dfs(1, l, r);
   	};
   	
   	int ans = 0;
   	int l = 1, r = (int)1e6;
   	while(l <= r) {
   		int mid = (l + r) >> 1;
   		bool flag = false;
   		for(int i = 1; i <= (int)1e6 - mid + 1; ++i) {
   			int left = i, right = i + mid - 1;
   			if(ok(left, right)) {
   				flag = true;
   				break;
   			}
   		}
   		if(flag) {
   			ans = mid;
   			l = mid + 1;
   		}
   		else r = mid - 1;
   	}
   	if(ans == 0) cout << "Nice work, Dima!";
   	else cout << ans;
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
