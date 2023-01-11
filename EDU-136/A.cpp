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
	int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int n, m; cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			bool f = false;
			for(int k = 0; k < 8; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if((0 <= nx) && (nx <= n - 1) && (0 <= ny) && (ny <= m - 1)) f = true;
			}
			if(!f) {
				cout << i + 1 << ' ' << j + 1; return 0;
			}
		}
	}
	cout << 1 << ' ' << 1;
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
