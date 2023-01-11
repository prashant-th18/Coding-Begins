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

const ll inf = (ll)1e18;
// *-> KISS*
int solve() {
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);
    int n; cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	sort(all(v));
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, inf)));
	for(int len = 1; len <= n; ++len) {
		for(int i = 0; i <= n - len; ++i) {
			int j = i + len - 1;
			if(len == 1) {
				dp[i][j][0] = dp[i][j][1] = (n - len + 1) * abs(v[i]);
			}
			else {
				dp[i][j][0] = min(dp[i][j][0], min(dp[i + 1][j][0] + (n - len + 1) * abs(v[i + 1] - v[i]), dp[i + 1][j][1] + 
							(n - len + 1) * abs(v[j] - v[i])));
				dp[i][j][1] = min(dp[i][j][1], min(dp[i][j - 1][0] + (n - len + 1) * abs(v[i] - v[j]), 
							dp[i][j - 1][1] + (n - len + 1) * abs(v[j] - v[j - 1])));
			}
		}
	}
	cout << min(dp[0][n - 1][0], dp[0][n - 1][1]);
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
