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
    int n; cin >> n;
	vector<array<ll, 4>> v(n);
	for(int i = 0; i < n; ++i) {
		pll h; cin >> h.ff >> h.ss;
		pll p = minmax(h.ff, h.ss);
		v[i] = {p.ff, p.ss, h.ff, h.ss};
	}
	auto f = [&](array<ll, 4> a, array<ll, 4> b) {
		if(a[0] != b[0]) return a[0] < b[0];
		return a[1] < b[1];
	};
	sort(all(v), f);
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		if(i == n - 1) {
			ans += v[i][1] + 1;
			continue;
		}
		int pre = i;
		ll maxx = v[i][1];
		vector<pll> h;
		++i;
		while(i < n && v[i][0] <= maxx) {
			h.push_back(pll(v[i][2], v[i][3]));
			++i;
		}
		sort(all(h), [&](pll a, pll b) { if(a.ss != b.ss) {return a.ss > b.ss;} return a.ff > b.ff; });
		reverse(all(h)); h.push_back(pll(v[pre][2], v[pre][3])); reverse(all(h));
		for(int j = 0; j < sz(h) - 1; ++j) {
			debug(h[j]);
			ans += (max(h[j].ss, h[j + 1].ff));
		}
		ans += (max(h[sz(h) - 1].ss, h[0].ff));
		ans += sz(h);
		--i;
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
