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
    vector<int> v(n), pre(n + 2), suf(n + 3, 0);
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    	pre[i + 1] = pre[i] + v[i];
    }
    for(int i = n - 1; i >= 0; --i) {
    	suf[i + 1] = suf[i + 2] + v[i];
    }
    int ans = INT_MIN;
    for(int i = 0; i < n - 1; ++i) {
    	int temp = pre[i] - (v[i] + v[i + 1]) + suf[i + 3];
    	ans = max(ans, temp);
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