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
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	ll sum = 0, ans = 1e9;
	for(int i = 0; i < n; ++i) {
		sum += v[i];
		ll here = i + 1;
		ll s = 0, pre = i + 1;
		for(int j = i + 1; j < n; ++j) {
			s += v[j];
			if(s > sum) {
				break;
			}
			else if(s == sum) {
				s = 0;
				here = max(here, j - pre + 1);
				pre = j + 1;
			}
			else {
				continue;
			}
		}
		if(pre == n) {
			// OK
			ans = min(ans, here);
		}
	}
	cout << ans;
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
