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

const int MAXX = (int)3e5 + 10;
vector<vector<int>> v;
vector<bool> sq(MAXX, false);
void init() {
	for(ll i = 0; i * i < MAXX; ++i) sq[i * i] = true;

	v.assign(MAXX, vector<int>(2, -1));
	for(ll i = 1; i < MAXX; ++i) {
		for(ll j = (ll)sqrt(i) + 10; j >= 0; --j) {
			// i = j * j + s * s
			ll num = j * j;
			num = i - num;
			if(num >= 0 && sq[num]) {
				v[i][0] = j, v[i][1] = (ll)sqrt(num);
				assert(v[i][0] * v[i][0] + v[i][1] * v[i][1] == i);
				break;
			}
		}
	}
}
// *-> KISS*
int solve() {
	ll n; cin >> n;
	ll pre = n;
	int p = 0;
	while(n % 2 == 0) n /= 2, ++p;
	if(p & 1) {
		if(n == 1) {
			ll a = (1LL << (p / 2));
			cout << a << ' ' << a; return 0;
		}
		else {
			n *= (1LL << 1);
			ll rem = p - 1;
			rem /= 2;
			rem = 1LL << (rem);
			if(n < MAXX && v[n][0] != -1) cout << rem * v[n][0] << ' ' << rem * v[n][1];
			else {
				cout << -1;
			}
			return 0;
		}
	}
	if(v[n][0] == -1) cout << -1;
	else {
		ll a = (1LL << (p / 2));
		cout << a * v[n][0] << ' ' << a * v[n][1];
		ll t1 = a * v[n][0], t2 = a * v[n][1];
		assert(t1 * t1 + t2 * t2 == pre);
	}
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
	int TET = 1;
	init();
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
