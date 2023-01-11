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
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
    int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> order(n);
	for(int i = 0; i < n; ++i) cin >> order[i];
	reverse(all(order));
	vector<int> par(n + 1, -1);
	vector<int> rank(n + 1, 1);
	
	auto find = [&](int node) {
		vector<int> t;
		while(par[node] > 0) {
			t.push_back(node);
			node = par[node];
		}
		for(auto val : t) par[val] = node;
		return node;
	};

	auto un = [&](int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		if(rank[a] > rank[b]) {
			rank[a] += rank[b];
			par[b] = a;
		}
		else {
			rank[b] += rank[a];
			par[a] = b;
		}
	};

	vector<bool> vis(n + 1, false);
	vector<string> ans;
	for(int i = 0; i < n; ++i) {
		int node = order[i];
		vis[node] = true;
		for(const auto& val : v[node]) {
			if(vis[val]) {
				un(node, val);
			}
		}
		if(rank[find(node)] == i + 1) ans.push_back("YES");
		else ans.push_back("NO");
	}
	reverse(all(ans));
	cout << ans[0];
	for(int i = 1; i < n; ++i) {
		cout << '\n' << ans[i];
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
