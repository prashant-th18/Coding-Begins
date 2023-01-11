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
    int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int>(m, 0));
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	for(int j = 0; j < m; ++j) {
		int maxx = 0;
		for(int i = 0; i < n; ++i) {
			maxx = max(maxx, v[i][j]);
		}
		ans += maxx - v[k - 1][j];
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
		cout << "Case #" << i << ": ";

        if (solve()) {
            break;
        }
        cout << '\n';
    }

	return 0;
}
// -> Keep It Simple Stupid!
