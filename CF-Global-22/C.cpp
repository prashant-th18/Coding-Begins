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

// *-> KISS*
int solve() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i] = abs(v[i]);
		v[i] %= 2;
	}
	vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(2, vector<bool>(2, false)));
	// 0 -> Alice
	// 1 -> Bob
	int su = 0;
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			dp[i][0][0] = (v[i] == 0);
			dp[i][0][1] = (v[i] == 1);
			dp[i][1][0] = (v[i] == 0);
			dp[i][1][1] = (v[i] == 1);
		}
		else {
			// Alice - Even
			// Even - Even
			// Odd - Odd
			if(v[i] == 0) {
				if(su & 1) {
					if(!dp[i - 1][1][0]) dp[i][0][0] = true;
					if(!dp[i - 1][1][1]) dp[i][0][1] = true;
					if(!dp[i - 1][0][0]) dp[i][1][0] = true;
					if(!dp[i - 1][0][1]) dp[i][1][1] = true;
				}
				else {
					if(!dp[i - 1][1][1]) dp[i][0][0] = true;
					if(!dp[i - 1][1][0]) dp[i][0][1] = true;
					if(!dp[i - 1][0][1]) dp[i][1][0] = true;
					if(!dp[i - 1][0][0]) dp[i][1][1] = true;
				}
			}
			else {
				if(su & 1) {
					if(!dp[i - 1][1][1]) dp[i][0][0] = true;
					if(!dp[i - 1][1][0]) dp[i][0][1] = true;
					if(!dp[i - 1][0][1]) dp[i][1][0] = true;
					if(!dp[i - 1][0][0]) dp[i][1][1] = true;
				}
				else {
					if(!dp[i - 1][1][0]) dp[i][0][0] = true;
					if(!dp[i - 1][1][1]) dp[i][0][1] = true;
					if(!dp[i - 1][0][0]) dp[i][1][0] = true;
					if(!dp[i - 1][0][1]) dp[i][1][1] = true;
				}
			}
				dp[i][0][0] = dp[i][0][0] | dp[i - 1][0][0];
				dp[i][0][1] = dp[i][0][1] | dp[i - 1][0][1];
				dp[i][1][0] = dp[i][1][0] | dp[i - 1][1][0];
				dp[i][1][1] = dp[i][1][1] | dp[i - 1][1][1];
		}
		cerr << dp[i][0][0] << ' ' <<  dp[i][0][1] << ' ' <<  dp[i][1][0] << ' ' << dp[i][1][1] << endl;
		su += v[i];
	}
	if(dp[n - 1][0][0]) cout << "ALICE";
	else cout << "BOB";
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
