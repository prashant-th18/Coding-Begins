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
    int n; cin >> n;
    vector<ll> v(n);
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    	int ok = 0;
    	ll pre = v[i];
    	while(v[i]) {
    		++ok;
    		v[i] >>= 1;
    	}
    	ll diff = (1LL << ok) - pre;
    	assert(diff <= pre);
    	ans.push_back({i, diff});
    }
    cout << sz(ans) << '\n';
    for(auto val : ans) cout << val.ff + 1 << ' ' << val.ss << '\n';
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
