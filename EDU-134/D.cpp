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

using vi = vector<int>;
using pv = pair<vi, vi>;
// *-> KISS*
int solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) cin >> b[i];
	// Apply BFS
	ll bit = 29, ans = 0;
	queue<pv> q;
	{
		pv t; t.ff = a; t.ss = b;
		q.push(t);
	}
	while(sz(q) > 0 && bit >= 0) {
		vector<pv> v;
		while(!q.empty()) {
			v.push_back(q.front());
			q.pop();
		}
		queue<pv> temp;
		bool f = true;
		for(int i = 0; i < sz(v); ++i) {
			vector<int> u = v[i].ff, d = v[i].ss;
			vector<int> u0, u1, d0, d1;
			for(int j = 0; j < sz(u); ++j) {
				if(u[j] & (1 << bit)) u1.push_back(u[j]);
				else u0.push_back(u[j]);
			}
			for(int j = 0; j < sz(d); ++j) {
				if(d[j] & (1 << bit)) d1.push_back(d[j]);
				else d0.push_back(d[j]);
			}
			if(sz(u0) == sz(d1) && sz(u1) == sz(d0)) {
				if(sz(u0) != 0) temp.push(pv(u0, d1));
				if(sz(u1) != 0) temp.push(pv(u1, d0));
			} 
			else {
				f = false; break;
			}
		}
		if(f) {
			ans += (1 << bit);
			q = temp;
		}
		else {
			for(int i = 0; i < sz(v); ++i) {
				q.push(v[i]);
			}
		}
		--bit;
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
