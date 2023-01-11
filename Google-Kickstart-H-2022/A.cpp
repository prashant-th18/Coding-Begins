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
    ll l, n; cin >> l >> n;
    ll curr = 0, steps = 0;
    char dir;
    vector<pair<ll, char>> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].ff >> v[i].ss;
    for(int i = 0; i < n; ++i) {
    	ll t = v[i].ff;
    	char ch = v[i].ss;
    	if(i == 0) {
    		if(ch == 'C') {
    			steps = t / l;
    			curr = t % l;
    		}
    		else {
    			steps = t / l;
				if(t % l == 0) curr = 0;
				else curr = l - (t % l);
    		}
    		dir = ch;
    	}
    	else {
    		if(ch == 'C') {
    			if(curr == 0) dir = ch;
    			ll tot = (t / l);
    			// bool pass = false;
    			if(curr + t % l >= l) {
    				++tot;
    			}
    			curr = (curr + (t % l)) % l;
    			if(tot > 0) {
    				if(dir == ch) steps += tot;
    				else {
    					steps += max(0LL, tot - 1);
    					dir = ch;
    				}
    			}
    		}
    		else {
    			if(curr == 0) dir = ch;
    			ll tot = t / l;
    			if((curr - (t % l) <= 0) && (t % l) != 0) {
    				++tot;
    			}
				curr = (curr - (t % l) + l) % l;
    			if(tot > 0) {
    				if(dir == ch) steps += tot;
    				else {
    					dir = ch;
    					steps += max(0LL, tot - 1);
    				}
    			}
    		}
    	}
    }
    cout << steps;
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
    	cout << "Case #" << i << ": ";
		// #ifdef LOCAL
        // 	cout << "##################" << '\n';
		// #endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	// #ifdef LOCAL
    // 	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	// #endif
	return 0;
}
// -> Keep It Simple Stupid!
