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
    ll n, k; cin >> n >> k;
    string s = "",  res = string(n, '.');
    cin >> s;
    int how = 0;
    ll g = -1e7, h = -1e7;
    for(int i = 0; i < n; ++i) {
    	if(s[i] == 'G') {
    		ll diff = abs(i - g);
    		if(diff <= k) continue;
    		else {
    			int in = min(n - 1, i + k);
    			while(res[in] == 'H') --in;
    			
    			++how;
    			g = in;
    			res[in] = 'G';
    		}
    	}
    	else {
    		ll diff = abs(i - h);
    		if(diff <= k) continue;
    		else {
    			int in = min(n - 1, i + k);
    			while(res[in] == 'G') --in;
    			
    			++how;
    			h = in;
    			res[in] = 'H';
    		}
    	}
    }
    cout << how << '\n' << res;
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