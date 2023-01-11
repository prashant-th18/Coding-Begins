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

ll mul(ll a, ll b) {
	return a * b % MOD;
}
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll sub(ll a, ll b) {
	return (a - b + MOD) % MOD;
}
// *-> KISS*
int solve() {
	int n; cin >> n;
	vector<vector<ll>> v(n, vector<ll>(2, 0));
	ll sq = 0, sim1 = 0, sim2 = 0;
	for(int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
		sq = add(sq, add(mul(v[i][0], v[i][0]), mul(v[i][1], v[i][1])));
		sim1 = add(sim1, v[i][0]);
		sim2 = add(sim2, v[i][1]);
	}
	ll px = 0, py = 0, S = 0;
	ll pre = sq;
	int q; cin >> q;
	while(q--) {
		ll x, y; cin >> x >> y;
		pre = sub(pre, mul(n, mul(px, px)));
		pre = sub(pre, mul(n, mul(py, py)));
		pre = add(pre, mul(2, mul(px, sim1)));
		pre = add(pre, mul(2, mul(py, sim2)));

		pre = add(pre, mul(n, mul(x, x)));
		pre = add(pre, mul(n, mul(y, y)));
		pre = sub(pre, mul(2, mul(x, sim1)));
		pre = sub(pre, mul(2, mul(y, sim2)));
		px = x, py = y;
		S = add(S, pre);
	}
	cout << S;
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
