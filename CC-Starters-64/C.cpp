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

vector<ll> pr;
vector<bool> vis;
const int N = 1e6 + 1;
void init() {
	vis.assign(N, false);
	pr.push_back(2);
	for(int i = 2; i < N; i += 2) vis[i] = true;
		
	for(int i = 3; i < N; i += 2) {
		if(!vis[i]) {
			pr.push_back(i);
			for(int j = i; j < N; j += 2 * i) vis[j] = true;
		}
	}
}
// *-> KISS*
int solve() {
    // int n; cin >> n;
    ll a, b; cin >> a >> b;
    ll gg = __gcd(a, b);
    ll ta = b / gg;
    debug(ta);
    bool flag = true;
    for(auto val : pr) {
    	if(__gcd(ta, a) == 1 || __gcd(ta, b) == 1) break;
    	while(ta % val == 0) ta /= val;
    }
    flag &= (__gcd(ta, b) == 1);
    if(!flag) cout << "NO";
    else cout << "YES";
	return 0;
}
int32_t main() {
	init();
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
