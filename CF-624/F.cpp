#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

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

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5;
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].ff;
	for(int i = 0; i < n; ++i) cin >> v[i].ss;
	sort(v.begin(), v.end());
	{
		map<int, vector<int>> cnt;
		int c = 1;
		for(int i = 0; i < n; ++i) cnt[v[i].ss].push_back(i);
		for(auto& val : cnt) {
			vector<int>& t = val.ss;
			for(int i = 0; i < sz(t); ++i) {
				v[t[i]].ss = c;
			}
			++c;
		}
	}
	debug(v);
	vector<ll> bit1(N + 1, 0), bit2(N + 1, 0);
	auto upd = [&](int in, vector<ll>& bit, ll del) {
		for(; in <= N; in += (in & (-in))) {
			bit[in] += del;
		}
	};
	auto sum = [&](int in, vector<ll>& bit) -> ll {
		ll s = 0;
		for(; in > 0; in -= (in & -in)) {
			s += bit[in];
		}
		return s;
	};
	ll ans = 0;
	for(int i = n - 1; i >= 0; --i) {
		ll elem = sum(N, bit2) - sum(v[i].ss - 1, bit2);
		ll s = sum(N, bit1) - sum(v[i].ss - 1, bit1);
		ans += s - (v[i].ff * elem);
		upd(v[i].ss, bit1, v[i].ff);
		upd(v[i].ss, bit2, 1);
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
