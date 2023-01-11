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
using pll = pair<ll, ll>;
const ll inf = (ll)1e18;
struct comp {
	bool operator()(const pll& a, const pll& b) const {
		if(a.ff != b.ff) return a.ff < b.ff;
		return a.ss < b.ss;
	}
};
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
	vector<int> b(n + 1);
	vector<vector<int>> ord(k + 1);
	// ord[i]  -> Will contain all those indices whose identifier is "i"
	for(int i = 0; i < n; ++i) {
		cin >> b[i + 1];
		ord[b[i + 1]].push_back(i + 1);
	}
	/* debug(ord); */
	vector<string> mat(k);
	for(int i = 0; i < k; ++i) cin >> mat[i];
	vector<vector<int>> satisfy(k + 1);
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < k; ++j) {
			if(mat[i][j] == '1') {
				satisfy[i + 1].push_back(j + 1);
			}
		}
	}
	/* debug(satisfy); */
	set<pll, comp> st;
	st.insert({0, 1});
	vector<ll> dist(n + 1, inf);
	vector<bool> vis(k + 1, false);
	dist[1] = 0;
	while(!st.empty()) {
		pll p = *(st.begin());
		st.erase(st.begin());
		if(p.ss == n) {
			cout << p.ff; return 0;
		}
		int node = p.ss;
		ll dis = p.ff;
		for(int& val : satisfy[b[node]]) {
			vector<int>& v = ord[val];
			if(vis[val]) continue;
			vector<int> here;
			for(auto& temp : v) {
				ll nd = abs(node - temp) + dis;
				if(nd <= dist[temp]) {
					auto it = st.find({dist[temp], temp});
					if(it != st.end()) st.erase(it);
					dist[temp] = nd;
					st.insert({abs(node - temp) + dis, temp});
				}
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
