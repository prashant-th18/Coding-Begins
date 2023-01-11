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
    int z = 0, o = 0, t = 0;
    for(int i = 0; i < n; ++i) {
    	int p; cin >> p;
    	if(p % 3 == 0) ++z;
    	else if(p % 3 == 1) ++o;
    	else ++t;
    }
    
    ll ans = 0;
    if(o == t) {
    	cout << o; return 0;
    }
    
    {
    	ll l1 = o - o % 4, l2 = t - t % 4;
    	
    	ans += min(l1, l2);
    	
    	ll t_ = min(l1, l2);
    	l1 -= t_;
    	l2 -= t_;
    	
    	o = o % 4 + l1;
    	t = t % 4 + l2;
    }
    
    ll mini = min(o, t);
    ll maxi = max(o, t);
    
    // if(maxi > 4) {
    // 	ll left = maxi - 4;
    	
    // 	maxi = 4;
    	
    // 	ans += left / 4 * 3;
    	
    // }
    
    if(mini == maxi) {
    	cout << ans + mini; return 0;
    }
    
    if(mini == 3) {
    	
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
