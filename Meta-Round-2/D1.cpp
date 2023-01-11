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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<int> bit(n + 1);
	auto upd = [&](int in, int del) {
		for(; in <= n; in += (in & (-in))) bit[in] += del;
	};
	auto sum = [&](int in) {
		ll s = 0;
		for(; in > 0; in -= (in & (-in))) s += bit[in];
		return s;
	};
	vector<vector<int>> b(4, vector<int>(n + 1, 0));
	auto up = [&](vector<int>& bitt, int in, int del) {
		for(; in <= n; in += (in & (-in))) bitt[in] += del;
	};
	auto su = [&](vector<int>& bitt, int in) {
		ll s = 0;
		for(; in > 0; in -= in & (-in)) s += bitt[in];
		return s;
	};
	for(int i = 0; i < n; ++i) {
		upd(i + 1, v[i]);
		up(b[v[i]], i + 1, 1);
	}
	ll ans = 0;
	for(int i = 0; i < m; ++i) {
		int x, y, z; cin >> x >> y >> z;
		// a[x] -> y 
		upd(x, -v[x - 1]);
		upd(x, y);
		up(b[v[x - 1]], x, -1);
		up(b[y], x, 1);
		v[x - 1] = y;

		ll left = sum(z), right = sum(n) - left;
		cerr << left << ' ' << right << endl;
		if(left == right) continue;
		
		if(left > right) {
			ll dif = left - right;
			ll l3 = su(b[3], z), l2 = su(b[2], z), l1 = su(b[1], z);
			ll r3 = su(b[3], n) - l3, r2 = su(b[2], n) - l2, r1 = su(b[1], n) - l1;

			// 3 - 1 
			// 3 - 2
			// 2 - 1
			ll op = 0;
			if(l3 > 0 && r1 > 0 && dif != 1) {
				ll el = dif / 2;
				el = min(el, min(l3, r1));
				dif -= el * 2;
				if(dif == 0) {
					ans += el; continue;
				}
				op += el;
				l3 -= el; r1 -= el;
			}
			if(l3 > 0 && r2 > 0) {
				int el = min(l3, min(r2, dif));
				dif -= el;
				if(dif == 0) {
					ans += op + el; continue;
				}
				op += el;
				l3 -= el; r2 -= el;
			}
			if(l2 > 0 && r1 > 0) {
				int el = min({dif, l2, r1});
				dif -= el;
				if(dif == 0) {
					ans += op + el; continue;
				}
				else {
					ans += -1;
				}
			}
		}
		if(left < right) {
			ll op = 0;
			ll dif = right - left;
			ll l3 = su(b[3], z), l2 = su(b[2], z), l1 = su(b[1], z);
			ll r3 = su(b[3], n) - l3, r2 = su(b[2], n) - l2, r1 = su(b[1], n) - l1;

			if(r3 > 0 && l1 > 0) {
				ll el = dif / 2;
				el = min(el, min(r3, l1));
				dif -= el * 2;
				if(dif == 0) {
					ans += el;
					continue;
				}
				op += el;
				r3 -= el; l1 -= el;
			}
			if(r3 > 0 && l2 > 0) {
				ll minn = min({dif, r3, l2});
				dif -= minn;
				if(dif == 0) {
					ans += op + dif;
					continue;
				}
				r3 -= minn; l2 -= minn;
				op += dif;
			}
			if(r2 > 0 && l1 > 0) {
				ll el = min({dif, r2, l1});
				dif -= el;
				if(dif == 0) {
					ans += op + el;
				}
				else ans += -1;
			}
		}
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
		#ifdef LOCAL
        	cerr << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
		cout << '\n';
    }
	#ifdef LOCAL
    	cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
