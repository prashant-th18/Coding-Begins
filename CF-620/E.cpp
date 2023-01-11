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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<vector<int>> v, lca;
vector<int> level;
void dfs(int node, int p, int lvl) {
	level[node] = lvl;
	lca[node][0] = p;
	for(int& val : v[node]) {
		if(val == p) continue;
		dfs(val, node, lvl + 1);
	}
}
void init() {
	for(int i = 1; i < 31; ++i) {
		for(int node = 1; node <= n; ++node) {
			int p = lca[node][i - 1];
			if(p != -1) lca[node][i] = lca[p][i - 1];
		}
	}
}
// *-> KISS*
int solve() {
    cin >> n;
	v.assign(n + 1, vector<int>());
	level.assign(n + 1, 0);
	lca.assign(n + 1, vector<int>(31, -1));
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, -1, 0);
	init();
	int q; cin >> q;
	
	auto diff = [&](int a, int b) {
		if(level[a] > level[b]) swap(a, b);
		int pa = a, pb = b;
		int d = level[b] - level[a];
		while(d > 0) {
			int jump = log2(d);
			b = lca[b][jump];
			d -= (1 << jump);
		}
		if(a == b) return level[pb] - level[pa];
		while(lca[a][0] != lca[b][0]) {
			for(int i = 30; i >= 0; --i) {
				if(lca[a][i] == -1 || lca[b][i] == -1 || lca[a][i] == lca[b][i]) continue;
				a = lca[a][i], b = lca[b][i];
				break;
			}
		}
		int par = lca[a][0];
		a = pa, b = pb;
		int c = level[a] + level[b] - 2 * level[par];
		return c;
	};

	while(q--) {
		int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
		bool flag = false;
		int initial = diff(a, b);
		if((initial <= k) && (k % 2 == initial % 2)) {
			flag = true;
		}
		initial = diff(a, x) + 1 + diff(b, y);
		if((initial <= k) && (k % 2 == initial % 2)) {
			flag = true;
		}
		initial = diff(a, y) + 1 + diff(b, x);
		if((initial <= k) && (k % 2 == initial % 2)) {
			flag = true;
		}
		/* initial = diff(a, x) + diff(b, x); */
		/* if(initial <= k && (k % 2 == initial % 2)) flag = true; */
		/* initial = diff(a, y) + diff(y, b); */
		/* if(initial <= k && (k % 2 == initial % 2)) flag = true; */
		if(flag) cout << "YES\n";
		else cout << "NO\n";	
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
