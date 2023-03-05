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
    string s; cin >> s;
    int q; cin >> q;
    while(q--) {
    	int t; cin >> t;
    	if(t == 1) {
    		int l, r; cin >> l >> r;
    		char ch; cin >> ch;
    		for(int i = l; i <= r; ++i) {
    			s[i - 1] = ch;
    		}
    	}
    	else {
    		int l, r; cin >> l >> r;
    		vector<int> vis(26, 0);
    		for(int i = l; i <= r; ++i) {
    			vis[s[i - 1] - 'a']++;
    		}
    		int o = 0;
    		for(int i = 0; i < 26; ++i) o += (vis[i] & 1);
    		
    		if(o <= 1) cout << "Yes\n";
    		else cout << "No\n";
    	}
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif
        if (solve()) {
            break;
        }
        // cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
