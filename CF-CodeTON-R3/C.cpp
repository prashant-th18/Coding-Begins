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
	string a, b; cin >> a >> b;
	auto alt = [&](string s) {
		string t = string(sz(s), '0');
		for(int i = 0; i < sz(s); ++i) {
			t[i] = (char)((1 - (s[i] - '0')) + '0');
		}
		return t;
	};
	vector<pair<int, int>> ans;
	auto print = [&]() -> void {
		assert(sz(ans) <= n + 5);
		cout << sz(ans) << '\n';
		for(auto val : ans) cout << val.ff + 1 << ' ' << val.ss + 1 << '\n';
	};
	auto do_it = [&]() {
		// a == b
		assert(a == b);
		int one = count(all(a), '1');
		if(n % 2 == 0 && one % 2 == 1) {
			for(int i = 0; i < n; ++i) {
				if(a[i] == '0') {
					ans.push_back({i, i}); 
					a[i] = '1';
					break;
				}
			}
			ans.push_back({0, n - 1});
			a = alt(a);
		}
		if(n % 2 == 1 && one == n) {
			ans.push_back({0, 0});
			ans.push_back({1, n - 1});
			cout << "YES\n"; print(); return;
		}
		else if(n % 2 == 1 && one % 2 == 1) {
			ans.push_back({0, 1});
			string z = a.substr(0, 2);
			z = alt(z);
			a[0] = z[0], a[1] = z[1];
			ans.push_back({0, n - 1});
			a = alt(a);
		}
		char ch = '1';
		for(int i = 0; i < n; ++i) {
			if(a[i] == ch) ans.push_back({i, i});
		}
		cout << "YES\n";
		/* if(ch == '0') ans.push_back({0, n - 1}); */
		print();
	};
	if(a == b) {
		do_it();
	}
	else if(alt(a) == b) {
		a = alt(a);
		ans.push_back({0, n - 1});
		do_it();
	}
	else cout << "NO";
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
