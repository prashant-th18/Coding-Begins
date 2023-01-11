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
vector<vector<pair<int, int>>> v;
vector<bool> vis;
vector<int> col;
bool dfs(int node, int color) {
	vis[node] = true;
	col[node] = color;
	for(auto& [x, val] : v[node]) {
		if(!vis[val]) {
			if(x == 0) {
				if(!dfs(val, color)) {
					return false;
				}
			}
			else {
				if(!dfs(val, 1 - color)) {
					return false;
				}
			}
		}
		else {
			if(x == 0) {
				if(col[val] != color) return false;
			}
			else {
				if(col[val] == color) return false;
			}
		}
	}
	return true;
}
// *-> KISS*
int solve() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
	v.assign(n + 1, vector<pair<int, int>>());
	vis.assign(n + 1, false);
	col.assign(n + 1, 0);
	for(int i = 0; i < m; ++i) {
		char ch; cin >> ch;
		int x = (ch == 'S' ? 0 : 1);
		int a, b; cin >> a >> b;
		v[a].push_back(pair<int, int>(x, b));
		v[b].push_back(pair<int, int>(x, a));
	}
	int c = 0;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			if(!dfs(i, 0)) {
				cout << 0; return 0;
			}
			++c;
		}
	}
	string s = string(c, '0');
	s = "1" + s;
	cout << s;
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
