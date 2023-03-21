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

int n;
int si;
int ux, uy, lx, ly;
int dx, dy;
vector<int> t;
vector<pair<int, int>> v;
vector<double> r;
void push(int in) {
	if(t[in]) {
		t[2 * in] = t[2 * in + 1] = 1;
		t[in] = 0;
	}
}
void update(int in, int s, int e, int qs, int qe) {
	if(qs > qe) return;
	if(s == qs && e == qe) {
		t[in] = 1;
	}
	else {
		push(in);
		int mid = (s + e) >> 1;
		update(2 * in, s, mid, qs, min(mid, qe));
		update(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe);
	}
}
int query(int in, int s, int e, int pos) {
	if(s > e) return 0;
	if(s == e) return t[in];
	
	push(in);
	int mid = (s + e) >> 1;
	if(pos <= mid) return query(2 * in, s, mid, pos);
	else return query(2 * in + 1, mid + 1, e, pos);
}
// *-> KISS*
int solve() {
	cin >> ux >> uy >> lx >> ly;
	cin >> dx >> dy;
	cin >> n;
	v.assign(n, pair<int, int>());
	r.assign(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> v[i].ff >> v[i].ss;
		cin >> r[i];
	}
	ll mn = min({abs(dx - ux), abs(dx - lx), abs(dy - uy), abs(dy - ly)});
	t.assign(4 * (mn + 10) + 1, 0);
	si = mn + 10;
	for(int i = 0; i < n; ++i) {
		ll x = v[i].ff, y = v[i].ss;
		long double d = sqrtl((x - dx) * (x - dx) + (y - dy) * (y - dy));
		long double d1 = d - r[i];
		if(d1 < 0) {
			ll d2 = ceil(d + r[i] - 1);
			d2 = min(d2, mn);
			debug("OK", 0, d2);
			update(1, 0, si - 1, 0, d2);
		}
		else {
			ll op1 = ceil(d1 + 1);
			ll op2 = ceil(d + r[i] - 1);
			if(op1 > mn) continue;
			op1 = max(0LL, op1);

			op2 = min(op2, mn);
			debug("YOLO", op1, op2);
			update(1, 0, si - 1, op1, op2);
		}
	}
	int ans = 0;
	for(int i = 1; i <= mn; ++i) {
		if(query(1, 0, si - 1, i) == 0) ++ans;
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
		cout << "Case " << i << ": ";
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
