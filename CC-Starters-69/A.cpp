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
    vector<int> ans1, ans2;
    for(int i = 0; i < 2 * n; i += 2) {
    	ans1.push_back(i);
    	ans2.push_back(i + 1);
    }
    bool ok = true;
    for(int i = 0; i < n; ++i) {
    	ok &= (s[ans1[i]] == s[ans2[i]]);
    }
    if(!ok) {
    	for(auto val : ans1) cout << val + 1 << ' ';
    	return 0;
    }
    ok = false;
    for(int i = 0; i < n - 1; ++i) {
    	if(s[ans2[i]] != s[ans1[i + 1]]) {
    		swap(ans2[i], ans1[i + 1]);
    		ok = true;
    		break;
    	}
    }
    if(!ok) cout << -1;
    else {
    	for(auto val : ans1) cout << val + 1 << ' ';
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
