#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

#ifdef LOCAL
	void debug_print(string s) {
		cerr << "\"" << s << "\"";
	}

	void debug_print(const char* s) {
		debug_print((string)s);
	}

	void debug_print(bool val) {
		cerr << (val ? "true" : "false");
	}

	void debug_print(int val) {
		cerr << val;
	}

	void debug_print(ll val) {
		cerr << val;
	}

	void debug_print(double val) {
		cerr << val;
	}

	template<typename F, typename S>
	void debug_print(pair<F, S> val) {
		cerr << "(";
		debug_print(val.first);
		cerr << ", ";
		debug_print(val.second);
		cerr << ")";
	}

	void debug_print(vector<bool> val) {
		cerr << "{";
		bool first = true;
		for (bool x : val) {
			if (!first) {
				cerr << ", ";
			} else {
				first = false;
			}
			debug_print(x);
		}
		cerr << "}";
	}

	template<typename T>
	void debug_print(T val) {
		cerr << "{";
		bool first = true;
		for (const auto &x : val) {
			if (!first) {
				cerr << ", ";
			} else {
				first = false;
			}
			debug_print(x);
		}
		cerr << "}";
	}

	void debug_print_collection() {
		cerr << endl;
	}

	template<typename First, typename... Args>
	void debug_print_collection(First val, Args... args) {
		cerr << " ";
		debug_print(val);
		debug_print_collection(args...);
	}

#define debug(...) cerr << "@@@ " << #__VA_ARGS__ << " ="; debug_print_collection(__VA_ARGS__);

#else
	#define debug(...) 
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


int n, e1, e2;
vector<vector<int>> v1, v2;
vector<vector<int>> lca1, lca2;
vector<bool> vis;
int t, maxx = -1;
void dfs(int node, int h = 0) {
	if(maxx < h) {
		maxx = h; 
		t = node;
	}
	vis[node] = true;
	for(const auto& val : v1[node]) {
		if(!vis[val]) {
			dfs(val, h + 1);
		}
	}
}
void d1(int node, int p, vector<vector<int>>& v, vector<vector<int>>& lca) {
	vis[node] = true;
	for(const auto& val : v[node]) {
		if(val == p) continue;
		lca[val][0] = node;
		d1(val, node, v, lca);
	}
}
// *-> KISS*
int solve() {
    cin >> n;
	v1.assign(n + 1, vector<int>());
	v2 = v1;
	vis.assign(n + 1, false);
	lca1.assign(n + 1, vector<int>(32, -1));
	lca2 = lca1;
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v1[a].push_back(b);
		v1[b].push_back(a);
		v2[a].push_back(b);
		v2[b].push_back(a);
	}
	dfs(1);
	e1 = t;
	maxx = -1;
	vis.assign(n + 1, false);
	dfs(e1);
	e2 = t;
	debug(e1, e2);
	vis.assign(n + 1, false);
	d1(e1, -1, v1, lca1);
	vis.assign(n + 1, false);
	d1(e2, -1, v2, lca2);
	for(int i = 1; i <= 30; ++i) {
		for(int j = 1; j <= n; ++j) {
			int pp = lca1[j][i - 1];
			if(pp != -1) {
				lca1[j][i] = lca1[pp][i - 1];
			}
			pp = lca2[j][i - 1];
			if(pp != -1) {
				lca2[j][i] = lca2[pp][i - 1];
			}
		}
	}
	int q; cin >> q; 
	while(q--) {
		int node, k; cin >> node >> k;
		int k1 = k;
		int ti = node;
		int ans = -1;
		while(k1 > 0) {
			int p = log2(k1);
			debug(p);
			if(lca1[ti][p] != -1) {
				ti = lca1[ti][p];
				k1 -= (1 << p);
				if(k1 == 0) {
					ans = ti;
					break;
				}
			}
			else break;
		}
		if(ans != -1) cout << ans << '\n';
		else {
			k1 = k, ti = node;
			while(k1 > 0) {
				int p = log2(k1);
				if(lca2[ti][p] != -1) {
					ti = lca2[ti][p];
					k1 -= (1 << p);
					if(k1 == 0) {
						ans = ti;
						break;
					}
				}
				else break;
			}
			cout << ans << '\n';
		}
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
