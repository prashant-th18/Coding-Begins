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

const int N = (int)1e9;
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    vector<ll> v(n + 1, N);
    for(int i = 0; i < m; ++i) {
    	ll a, b; cin >> a >> b;
    	if(a > b) swap(a, b);
    	v[a] = min(v[a], b);
    }
    ll ans = 0;
    ll hold = n + 1; // I can't taqke elements from hold ahead
    for(ll i = n; i >= 1; --i) {
    	if(v[i] == N) {
    		ans += (hold - i);
    	}
    	else {
    		hold = min(hold, v[i]);
    		ans += (hold - i);
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
