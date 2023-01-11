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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

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

// *-> KISS*
int solve() {
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<vector<int>> pre(n + 1, vector<int>(30, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 30; ++j) {
			pre[i + 1][j] = pre[i][j] + ((v[i] >> j) & 1);
		}
	}
	vector<int> dp(n, -1), rev(n, -1);
	// dp[i] will tell the minimum odd length such that your xor becomes zero
	vector<int> order;
	for(int i = 0; i < n; ++i) {
		if(v[i] != 0) order.push_back(i);
	}
	for(int i = 0; i < n; ++i) {
		if(v[i] == 0) dp[i] = 1;
		else {
			int ind = lower_bound(all(order), i) - begin(order);
			int x = 0;
			for(int j = ind, cnt = 0; j < sz(order) && cnt < 1000; ++j, ++cnt) {
				x = x xor v[order[j]];
				if(x == 0) {
					int len = order[j] - i;
					if(len % 2 == 0) {
						dp[i] = len;
						break;
					}
				}
			}
		}
	}
	for(int i = n - 1; i >= 0; --i) {
		if(v[i] == 0) rev[i] = 1;
		else {
			int ind = lower_bound(all(order), i) - begin(order);
			int x = 0;
			for(int j = ind, cnt = 0; j >= 0 && cnt < 1000; --j, ++cnt) {
				x ^= v[order[j]];
				if(x == 0) {
					int len = i - order[j];
					if(len % 2 == 0) {
						rev[i] = len; break;
					}
				}
			}
		}
	}
	while(q--) {
		int a, b; cin >> a >> b;
		--a, --b;
		bool yes = true;
		bool is0 = true;
		for(int j = 0; j < 30; ++j) {
			yes &= ((pre[b + 1][j] - pre[a][j]) % 2 == 0);
			is0 &= ((pre[b + 1][j] - pre[a][j]) == 0);
		}
		if(yes) {
			if(is0) {
				cout << 0;
			}
			else {
					int x = dp[a], y = rev[b];
					if(x + a > b) x = -1;
					if(b - y < a) y = -1;
					if(x == -1 && y == -1) cout << -1;
					else if((b - a) % 2 == 0) cout << 1;
					else if((v[a] == 0 || v[b] == 0)) cout << 1;
					else cout << 2;
			}
		}
		else cout << -1;
		cout << '\n';
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
