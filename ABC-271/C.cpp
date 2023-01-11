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
	multiset<int> st;
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		st.insert(t);
	}
	int s = 0, e = n, ans = 0;
	while(s <= e) {
		int mid = (s + e) >> 1;
		auto c = st;
		int how = 0;
		for(int i = 1; i <= mid; ++i) {
			if(c.find(i) != c.end()) {
				c.erase(c.find(i));
			}
			else ++how;
		}
		if(sz(c) >= 2 * how) {
			ans = mid; s = mid + 1;
		}
		else e = mid - 1;
	}
	cout << ans;
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
