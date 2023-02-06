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
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
    	int t; cin >> t;
    	v[i] = t % 2;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
    	int diff = -1;
    	for(int j = i + 1; j < n; ++j) {
    		if(v[j] != v[i]) {
    			diff = j - i - 1;
    			i = j - 1;
    			break;
    		}
    	}
    	if(diff == -1) {
    		ans += (n - 1 - i);
    		break;
    	}
    	else {
    		ans += diff;
    	}
    }
    cout << ans;
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