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
const ll inf = (ll)1e18;

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
vector<ll> pre, t, v;
ll sum = 0;
void build(int in, int s, int e) {
	if(s == e) t[in] = pre[s];
	else {
		int mid = (s + e) >> 1;
		build(2 * in, s, mid);
		build(2 * in + 1, mid + 1, e);
		t[in] = min(t[2 * in], t[2 * in + 1]);
	}
}
void update(int in, int s, int e, int pos, ll nval) {
	if(s > e) return;
	if(s == e) {
		t[in] = nval;
	}
	else {
		int mid = (s + e) >> 1;
		if(pos <= mid) update(2 * in, s, mid, pos, nval);
		else update(2 * in + 1, mid + 1, e, pos, nval);
		t[in] = min(t[2 * in], t[2 * in + 1]);
	}
}
int query(int in, int s, int e, int qs, int qe) {
	if(s > e) return n + 1;
	if(s == e) {
		return s;
	}
	else {
		int mid = (s + e) >> 1;
		ll val1 = t[2 * in], val2 = t[2 * in + 1];
		if(val1 - sum < 0) {
			return query(2 * in, s, mid, qs, min(qe, mid));
		}
		return query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe);
	}
}
// *-> KISS*
int solve() {
	sum = 0;
    cin >> n;
	v.assign(n, 0);
	pre.assign(n + 1, 0);
	t.assign(4 * n, 0);
	vector<ll> pre2(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		pre[i + 1] = pre[i] + v[i];
		pre2[i + 1] = pre2[i] + 1LL * (n - i) * v[i];
	}
	build(1, 1, n);
	// remember sum is gloval
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		// remember 1 based
		int in = query(1, 1, n, i + 1, n);
		debug(in);
		if(v[i] < 0) {}
		else {
		if(in == n + 1 || pre[in] - sum >= 0) {
			// Take all
			ll how = pre2[n] - pre2[i];
			debug(how);
			ans += how;
		}
		else {
			ll how = (pre2[in - 1] - pre2[i]) - ((n - in + 1) * (pre[in - 1] - pre[i]));
			debug(how);
			ans += how;
		}}
		update(1, 1, n, i + 1, inf);
		sum += v[i];
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
		cout << "Case #" << i << ": ";
		if (solve()) {
            break;
        }
        cout << '\n';
    }
	return 0;
}
// -> Keep It Simple Stupid!
