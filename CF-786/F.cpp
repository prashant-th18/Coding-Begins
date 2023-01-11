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
    int n, m, q; cin >> n >> m >> q;
	// Bit Area
	vector<int> bit(m + 1, 0);
	auto upd = [&](int in, int del) {
		for(; in <= m; in += (in & (-in))) {
			bit[in] += del;
		}
	};
	auto sum = [&](int in) {
		in = min(in, m);
		int s = 0;
		for(; in > 0; in -= (in & (-in))) {
			s += bit[in];
		}
		return s;
	};
	vector<vector<int>> b(m, vector<int>(n + 1, 0));
	auto update = [&](int j, int in, int del) {
		for(; in <= n; in += (in & (-in))) {
			b[j][in] += del;
		}
	};
	auto SUM = [&](int j, int in) {
		int s = 0;
		for(; in > 0; in -= (in & (-in))) {
			s += b[j][in];
		}
		return s;
	};
	// Bit Area Closed
	vector<vector<bool>> v(n, vector<bool>(m, false));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if(ch == '*') {
				v[i][j] = true;
				upd(j + 1, 1);
				update(j, i + 1, 1);
			}
			else v[i][j] = false;
		}
	}
	while(q--) {
		int x, y; cin >> x >> y;
		--x, --y;
		if(v[x][y]) {
			v[x][y] = false;
			upd(y + 1, -1);
			update(y, x + 1, -1);
		}
		else {
			v[x][y] = true;
			upd(y + 1, 1);
			update(y, x + 1, 1);
		}
		int total = sum(m);
		if(total % n == 0) {
			// [1 .. total / n]
			cout << total - sum(total / n);
		}
		else {
			// [1 .. total / n + 1]
			int s = total - sum(total / n + 1);
			int mid = sum(total / n + 1) - sum(total / n);
			if(mid > total % n) {
				// total % m
				int w = SUM(total / n, n) - SUM(total / n, total % n);
				s += (mid - (total % n));
				w -= (mid - total % n);
				s += w;
			}
			else {
				// mid < (total % n)
				s += abs(SUM(total / n, total % n) - mid);
			}
			cout << s;
		}
		cout << '\n';
	}
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
