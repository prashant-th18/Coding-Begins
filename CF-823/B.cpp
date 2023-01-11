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
using pll = pair<ll, ll>;

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
    ll n; cin >> n;
	vector<pll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].ff;
	for(int i = 0; i < n; ++i) cin >> v[i].ss;
	sort(v.begin(), v.end());
	vector<ll> x(n), t(n);
	for(int i = 0; i < n; ++i) x[i] = v[i].ff, t[i] = v[i].ss;
	vector<ll> left(n), right(n);
	{
		left[0] = 0;
		for(int i = 1; i < n; ++i) {
			ll t1 = t[i];
			ll t2 = x[i] - x[left[i - 1]] + t[left[i - 1]];
			if(t1 >= t2) left[i] = i;
			else left[i] = left[i - 1];
		}

		right[n - 1] = n - 1;
		for(int i = n - 2; i >= 0; --i) {
			ll t1 = t[i];
			ll t2 = x[right[i + 1]] - x[i] + t[right[i + 1]];
			if(t1 >= t2) right[i] = i;
			else right[i] = right[i + 1];
		}
	}
	double ans = 1e12, c = -1;
	auto fun = [&](int i, int j) {
		double mid = (double)(x[i] + x[j]) / 2;
		// ith se left
		// jth se right
		double t1 = t[left[i]] + abs(mid - x[left[i]]);
		double t2 = t[right[j]] + abs(mid - x[right[j]]);
		double minn = max(t1, t2);
		if(minn <= ans) {
			ans = minn;
			c = mid;
		}
	};
	/* fun(0, 0); fun(n - 1, n - 1); */
	for(int i = 0; i < n; ++i) fun(left[i], right[i]);
	cout << c;
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
