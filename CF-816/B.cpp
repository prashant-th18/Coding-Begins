#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    ll n, k, b, s; cin >> n >> k >> b >> s;
	ll ss = s, bpre = b;
	vector<ll> v(n);
	if(k * b > s) {
		cout << -1; return 0;
	}
	else {
		v[0] = k * b;
		s -= k * b;
		ll mini = min(k - 1, s);
		v[0] += mini;
		s -= mini;
		if(n == 1) {
			if(s > 0) {
				cout << -1; return 0;
			}
		}
		else {
			ll left = n - 1;
			ll q = s / left, rem = s % left;
			for(int i = 1; i < n; ++i) {
				v[i] = q;
				v[i] += (rem-- > 0);
			}
		}
		ll aa = 0, bb = 0;
		for(int i = 0; i < n; ++i) {
			aa += v[i];
			bb += v[i] / k;
		}
		debug(aa, bb);
		if(aa != ss || bb != bpre) {
			cout << -1; return 0;
		}
		for(auto& val : v) cout << val << ' ';
	}
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
