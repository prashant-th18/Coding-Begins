#include <algorithm>
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

string get(string s, int num) {
	string f = s.substr(0, num);
	string rev = s; reverse(begin(rev), end(rev));
	f += rev;
	f += s.substr(num);
	return f;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    string t; cin >> t;
    string keep = t;
    
    string ex = t; reverse(all(ex));
    t += ex;
    
    vector<int> pref(sz(t) + 1, 0);
    pref[0] = -1;
    int maxx = 0;
    for(int i = 1; i <= sz(t); ++i) {
    	int k = pref[i - 1];
    	while(k >= 0 && t[k] != t[i - 1]) {
    		k = pref[k];
    	}
    	pref[i] = k + 1;
    	if(i >= sz(t) / 2) maxx = max(maxx, pref[i]);
    }
    maxx %= n;
    string ans = t.substr(0, maxx);
    int left = n - maxx;
    string here;
    for(int i = maxx, cnt = 0; cnt < left && i < sz(t); ++i, ++cnt) {
    	here += t[i];
    }
    
    reverse(all(here));
    ans += here;
    
    string real = get(ans, maxx);
    if(real == keep) cout << ans << '\n' << maxx;
    else cout << -1;
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