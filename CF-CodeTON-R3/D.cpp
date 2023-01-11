#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 998244353;
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

const int N = 3e5;
ll cnt(ll num, ll pre) {
	// [1 .. num] 
	// All those whose gcd with pre == 1
	vector<ll> v;
	for(ll i = 1; i * i <= pre; ++i) {
		if(pre % i == 0) {
			v.push_back(i);
			while(pre % i == 0) pre /= i;
		}
	}
	if(pre != 1) v.push_back(pre);

	int n = v.size();
	ll temp = 0;
	for(int i = 1; i < (1 << n); ++i) {
		ll prod = 1;
		for(int j = 0; j < n; ++j) {
			if(i >> j & 1) prod *= v[j];
		}
		ll contri = num / prod;
		// Add or subtract
		if(__builtin_popcount(i) % 2 == 0) {
			temp = (temp - contri + MOD) % MOD;
		}
		else {
			temp = (temp + contri + MOD) % MOD;
		}
	}
	ll ans = 0;
	return ans = (num - temp + MOD) % MOD;
}
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	ll ans = 1;
	auto mul = [&](ll a, ll b) {
		return a % MOD * (b % MOD) % MOD;
	};
	for(int i = 1; i < n; ++i) {
		ll gg = gcd(v[i], v[i - 1]);
		if(gg != v[i]) {
			ans = 0; break;
		}
		ll num = m / v[i];
		ll pre = v[i - 1] / gg;
		ll res = cnt(num, pre);
		ans = mul(ans, res);
	}
	cout << ans;
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
