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
using pll = pair<ll, ll>;

// *-> KISS*
int solve() {
    int n; cin >> n;
	deque<pll> v(n);	
	for(int i = 0; i < n; ++i) {
		cin >> v[i].ff;
		v[i].ss = v[i].ff;
	}
	for(int i = 0; sz(v); ++i) {
		sort(all(v), greater<pll>());
		if(v[0].ff == 0) {
			while(sz(v)) {
				cout << v.front().ss << ' ';
				v.pop_front();
			}
			break;
		}
		else {
			cout << v[0].ss << ' ';
			int num = v[0].ff;
			v.pop_front();
			for(int j = 0; j < sz(v); ++j) {
				int x = v[j].ff & num;
				v[j].ff -= x;
			}
		}
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
