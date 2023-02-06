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

// https://www.codingninjas.com/codestudio/library/count-inversions-using-fenwick-tree
// *-> KISS*
int solve() {
    int n; cin >> n;
	// n! * inversions of sorted iota vector
	
	vector<int> v(n);
	iota(all(v), 1);
	vector<int> t;
	for(int i = 0; i < n; ++i) {
		t.push_back(v[i]);
	}
	for(int i = n - 1; i >= 0; --i) {
		t.push_back(v[i]);
	}
	
	ll ans = 1;
	for(ll i = 1; i <= n; ++i) {
		ans = ans * i % MOD;
	}
	vector<ll> bit(n + 1, 0);
	auto upd = [&](int in, ll val) {
		while(in <= n) {
			bit[in] += val;
			in += (in & (-in));
		}
	};
	auto query = [&](int in) {
		ll sum = 0;
		while(in > 0) {
			sum += bit[in];
			in -= (in & (-in));
		}
		return sum;
	};
	ll cnt = 0;
	for(int i = 2 * n - 1; i >= 0; --i) {
		cnt += query(t[i] - 1);
		upd(t[i], 1);
	}
	cnt %= MOD;
	cout << (cnt * ans) % MOD; 
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    cin >> TET;
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
