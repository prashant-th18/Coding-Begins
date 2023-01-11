// Recursion complexity * iterating on 18-19 digits * iterating on 0 - 9
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

ll ans = 0;
const int N = 20;
string s;
vector<ll> orig, v;
vector<ll> fact(N, 1);
set<vector<ll>> st;
void init() {
	for(ll i = 2; i < N; ++i) fact[i] = i * fact[i - 1];
}
ll every() {
	ll t = 0, c = 0;
	c = accumulate(all(v), 0);
	t = fact[c];
	for(int i = 0; i < 10; ++i) {
		t /= fact[v[i]];
	}
	return t;
}
ll zero() {
	if(v[0] == 0) return 0;
	ll t = v[0]; 
	--v[0];
	ll c = 0;
	for(int i = 0; i <= 9; ++i) c += v[i];
	t *= fact[c];
	++v[0];
	for(int i = 0; i < 10; ++i) t /= fact[v[i]];
	return t;
}
void fun(int in, int k) {
	if(in == sz(s)) {
		if(k != 0) return;
		for(int i = 0; i <= 9; ++i) {
			if(orig[i] != 0 && v[i] == 0) return;
		}
		if(st.count(v)) return;
		st.insert(v);
		ll t1 = every();
		ll t2 = zero();
		ans += (t1 - t2);
		return;
	}
	if(k == 0) fun(in + 1, k);
	else {
		// Take it
		v[s[in] - '0']--;
		fun(in + 1, k - 1);
		v[s[in] - '0']++;
		fun(in + 1, k);
	}
}
// *-> KISS*
int solve() {
    cin >> s;
	orig.assign(10, 0); v = orig;
	for(int i = 0; i < sz(s); ++i) {
		orig[s[i] - '0']++;
		v[s[i] - '0']++;
	}
	init();
	/*string p = "";
	for(int i = 0; i < 10; ++i) {
		if(orig[i] != 0) p += ((i) + '0');
	}
	s = p;
	*/
	for(int i = 0; i <= sz(s); ++i) {
		fun(0, i);
	}
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
