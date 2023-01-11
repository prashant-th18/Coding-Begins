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

vector<bool> vis;
vector<int> cc;
void dfs(vector<vector<int>>& c, int node) {
	cc.push_back(node);
	vis[node] = true;
	for(const auto& val : c[node]) {
		if(!vis[val]) {
			dfs(c, val);
		}
	}
}
// *-> KISS*
int solve() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
    int n, m; cin >> n >> m;
	vector<int> v(n + 1);
	for(int i = 0; i < n; ++i) {
		cin >> v[i + 1];
	}
	vector<vector<int>> edges(m, vector<int>(3, 0));
	for(int i = 0; i < m; ++i) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	}
	sort(all(edges), [&](vector<int>& a, vector<int>& b) {
		return a[2] < b[2];
	});
	if(is_sorted(all(v))) {
		cout << -1; return 0;
	}
	int s = 0, e = m - 1, ans = -1;
	while(s <= e) {
		int mid = (s + e) >> 1;
		vector<vector<int>> c(n + 1);
		for(int i = mid; i <= m - 1; ++i) {
			c[edges[i][0]].push_back(edges[i][1]);
			c[edges[i][1]].push_back(edges[i][0]);
		}
		vis.assign(n + 1, false);
		vector<int> cpy = v;
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) {
				dfs(c, i);
				vector<int> values;
				for(int j = 0; j < sz(cc); ++j) {
					values.push_back(v[cc[j]]);
				}
				sort(all(values));
				sort(all(cc));
				for(int j = 0; j < sz(cc); ++j) {
					cpy[cc[j]] = values[j];
				}
				cc.clear();
			}
		}
		if(is_sorted(all(cpy))) {
			ans = edges[mid][2];
			s = mid + 1;
		}
		else e = mid - 1;
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
