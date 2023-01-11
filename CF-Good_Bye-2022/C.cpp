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
    int o = 0, e = 0;
    map<ll, ll> mp;
    bool ok = true;
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    	o += (v[i] % 2 == 1);
    	e += (v[i] % 2 == 0);
    	++mp[v[i]];
    	if(mp[v[i]] >= 2) {
    		ok = false;
    	}
    }
    if(!ok) {
    	cout << "NO"; return 0;
    }
    if(n == 2) {
    	if(v[0] == v[1]) cout << "NO";
    	else cout << "YES";
    }
    else {
    	if(o >= 2 && e >= 2) cout << "NO";
    	else cout << "YES";
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