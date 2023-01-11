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
    ll n, m; cin >> n >> m;
	vector<ll> v(n + 1);
	v[1] = 1;
	ll sum = 1;
	for(ll i = 2; i <= n; ++i) {
		v[i] = sum;
		ll div = 2;
		while(div <= i) {
			ll given = i / div;
			ll next = i / given + 1;
			v[i] = (v[i] + (v[given] * (next - div) % m)) % m;
			div = next;
			cout << i << endl << endl << endl;
		}
		sum = (sum + v[i]) % m;
	}
	cout << v[n];
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
