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
	string s; cin >> s;
	int first = s.find('1');
	if(first == -1) {
		cout << 0; return 0;
	}
	string ans = s.substr(first);
	first = 0;
	while(first < sz(ans) && ans[first] == '1') ++first;
	if(first == sz(ans)) {
		cout << ans;
		return 0;
	}
	first = ans.find('0');
	s = ans;
	debug(ans);
	vector<bool> best(sz(ans), false);
	for(int i = 0; i < first; ++i) {
		// Start from i
		vector<bool> here(sz(ans), false);
		for(int j = 0; j < first; ++j) here[j] = true;
		/* bool overcome = false; */
		// [i .. i + si]
		bool dont = false, overcome = false;;
		for(int j = first; j < sz(ans); ++j) {
			// compare 
			// [i .. i + sz(ans)] 
			// with
			// [first .. sz(ans)]
			if(s[j] == '1') here[j] = true;
			else {
				if(s[j - first + i] == '1') here[j] = true;
				
				if(!overcome && best[j] && !here[j]) {
					dont = true; break;
				}
			}
			if(here[j] && (!best[j])) overcome = true;
		}
		bool use = false;
		for(int j = 0; j < sz(ans) && !use; ++j) {
			if(!best[j] && here[j]) {
				use = true;
			}
		}
		if(use && !dont) {
			best = here;
		}
	}
	string ok = "";
	for(int i = 0; i < sz(ans); ++i) {
		if(best[i]) ok += "1";
		else ok += "0";
	}
	cout << ok;
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
