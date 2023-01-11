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

// *-> KISS*
int solve() {
	string s; cin >> s;
	int n = sz(s);
	vector<vector<int>> dp(n, vector<int>(n, -1));
	// 0 -> draw, 1 -> alice, 2 -> bob
	for(int len = 2; len <= n; len += 2) {
		for(int i = 0; i < n - len + 1; ++i) {
			int j = i + len - 1;
			// We are assuming that till now the individual strings are same
			if(len == 2) {
				if(s[i] == s[j]) dp[i][j] = 0;
				else dp[i][j] = 1;
			}
			else {
					char ch = s[i];
					// i + 1 ... j
					char mini = min(s[i + 1], s[j]);
					if(mini < ch) {
						dp[i][j] = 2;
					}
					else if(mini == ch) {
						int minn = min(dp[i + 2][j], dp[i + 1][j - 1]);
						int maxx = max(dp[i + 2][j], dp[i + 1][j - 1]);
						if(maxx == 0) dp[i][j] = 0;
						else if(maxx == 1) {
							if(minn == 0) dp[i][j] = 0;
							else {
								dp[i][j] = 1;
								continue;
							}
						}
						else {
							dp[i][j] = 2;
							/*if(minn == 1) {
								dp[i][j] = 1; continue;
							}
							else if(minn == 0) dp[i][j] = 0;
							else dp[i][j] = 2;
							*/
						}
					}
					else {
						dp[i][j] = 1; continue;
					}
					ch = s[j];
					mini = min(s[i], s[j - 1]);
					if(mini < ch) {
						if(dp[i][j] == -1) dp[i][j] = 2;
					}
					else if(mini == ch) {
						int minn = min(dp[i][j - 2], dp[i + 1][j - 1]);
						int maxx = max(dp[i][j - 2], dp[i + 1][j - 1]);
						if(maxx == 0) dp[i][j] = 0;
						else if(maxx == 1) {
							if(minn == 1) {
								dp[i][j] = 1;
							}
							else {
								dp[i][j] = 0;
							}
						}
						else {
							if(dp[i][j] == -1) dp[i][j] = 2;
							/*if(minn == 1) dp[i][j] = 1;
							else if(minn == 0) dp[i][j] = 0;
							else if(dp[i][j] == -1) dp[i][j] = 2; */
						}
					}
					else dp[i][j] = 1;
				}
		}
	}
	if(dp[0][n - 1] == 0) cout << "Draw";
	else if(dp[0][n - 1] == 1) cout << "Alice";
	else cout << "Bob";
	return 0;
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool test = true;
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
