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

int n, m;
vector<vector<int>> v;
vector<bool> vis, onstack;
vector<int> order;
bool dfs(int node) {
	vis[node] = true;
	onstack[node] = true;
	
	for(const auto& val : v[node]) {
		if(vis[val]) {
			if(onstack[val]) {
				// Cycle Found
				onstack[val] = false;
				onstack[node] = false;
				order.push_back(node);
				return true;
			}
		}
		else {
			if(dfs(val)) {
				order.push_back(node);
				if(onstack[node] == false) {
					return false;
				}
				else {
					onstack[node] = false;
					return true;
				}
			}
			if(!order.empty()) return false;
		}
	}
	
	onstack[node] = false;
	return false;
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    onstack = vis;
    for(int i = 0; i < m; ++i) {
    	int a, b; cin >> a >> b;
    	v[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i) {
    	if(!vis[i]) {
    		dfs(i);
    		
    		if(!order.empty()) break;
    	}
    }
    if(order.empty()) {
    	cout << "IMPOSSIBLE"; return 0;
    }
    reverse(all(order));
    order.push_back(order[0]);
    cout << sz(order) << '\n';
    for(auto val : order) cout << val << ' ';
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
		// #ifdef LOCAL
        // 	cout << "##################" << '\n';
		// #endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	// #ifdef LOCAL
    // 	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	// #endif
	return 0;
}
// -> Keep It Simple Stupid!
