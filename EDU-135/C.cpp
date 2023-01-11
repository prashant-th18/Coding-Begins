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
int digCal(int num) {
	int cnt = 0;
	while(num) {
		++cnt;
		num /= 10;
	}
	return cnt;
}
// *-> KISS*
int solve() {
	int n; cin >> n;
	map<int, int> mp1, mp2;
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		mp1[t]++;
	}
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		if(mp1.count(t) && mp1[t] != 0) --mp1[t];
		else {
			mp2[t]++;
		}
	}
	multiset<pll> v;
	vector<int> d1(10), d2(10);
	auto fun = [&](map<int, int>& mp, vector<int>& d, int in) -> void {
		for(auto& [x, y] : mp) {
			if(y == 0) continue;
			else {
				int num = digCal(x);
				d[num] += y;
				for(int j = 0; j < y; ++j) v.insert(pll(x, in));
			}
		}
	};
	fun(mp1, d1, 0); fun(mp2, d2, 1);
	ll cnt = 0;
	while(sz(v)) {
		pll p = *(v.rbegin());
		v.erase(v.find(*(v.rbegin())));
		if(p.ss == 0 && (mp1[p.ff] == 0 || d1[digCal(p.ff)] == 0)) continue;
		else if(p.ss == 1 && (mp2[p.ff] == 0 || d2[digCal(p.ff)] == 0)) continue;
		if(p.ss == 0) mp1[p.ff]--;
		if(p.ss == 1) mp2[p.ff]--;
		int num = p.ff;
		int dig = digCal(num);
		if(p.ss == 0) d1[dig]--;
		else d2[dig]--;
		if(p.ss == 0) {
			if(mp2[dig]) {
				mp2[dig]--; d2[1]--; ++cnt;
			}
			else {
				mp1[dig]++;
				d1[1]++;
				++cnt;
				v.insert(pll(dig, 0));
			}
		}
		else {
			if(mp1[dig]) {
				mp1[dig]--; d1[1]--; ++cnt;
			}
			else {
				mp2[dig]++;
				d2[1]++;
				++cnt;
				v.insert(pll(dig, 1));
			}
		}
	}
	cout << cnt;
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
