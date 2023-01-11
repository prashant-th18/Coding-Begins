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
    string s; cin >> s;
    int a = count(all(s), 'L'), b = n - a;
    if(a == n || a == 0) {
    	cout << -1;
    }
    else {
    	bool ok = false;
    	int in = -1;
    	for(int i = 0; i < n - 1; ++i) {
    		if(s[i] == 'R' && s[i + 1] == 'L') {
    			ok = true;
    		}
    		else if(s[i] == 'L' && s[i + 1] == 'R') in = i;
    	}
    	if(ok) cout << 0;
    	else cout << in + 1;
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