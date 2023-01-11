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

const int S = 10000;
using pll = pair<ll, ll>;

// *-> KISS*
int solve() {
    int n, s; cin >> n >> s;
	vector<pll> v(n);
	for(int i = 0; i < n; ++ i) cin >> v[i].ff >> v[i].ss;
	vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(2, vector<bool>(S + 1, false)));
	// dp[i][j][k] -> 
	// Till index i, if I have placed jth orientation of ith card, is it possible to make sum k
	dp[0][0][0] = dp[0][1][0] = true;
	for(int i = 1; i <= n; ++i) {
		for(int sum = 0; sum <= S; ++sum) {
			if(v[i - 1].ff <= sum) {
				dp[i][0][sum] = (dp[i - 1][0][sum - v[i - 1].ff] | dp[i - 1][1][sum - v[i - 1].ff]);
			}
			if(v[i - 1].ss <= sum) {
				dp[i][1][sum] = (dp[i - 1][0][sum - v[i - 1].ss] | dp[i - 1][1][sum - v[i - 1].ss]);
			}
		}
	}
	if(!dp[n][0][s] && !dp[n][1][s]) {
		cout << "No"; return 0;
	}
	string ans;
	auto fun = [&](const auto& fun, int index, int sum) -> void {
		if(index == 0) return;
		int elem = v[index - 1].ff;
		debug(elem, sum);
		if(sum >= elem && (dp[index - 1][0][sum - elem] || dp[index - 1][1][sum - elem])) {
			ans = "H" + ans;
			fun(fun, index - 1, sum - elem);
		}
		else {
			ans = "T" + ans;
			fun(fun, index - 1, sum - v[index - 1].ss);
		}
	};
	fun(fun, n, s);
	cout << "Yes\n";
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
