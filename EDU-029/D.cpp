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
    int n, q, m; cin >> n >> q >> m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<array<int, 3>> p(q);
	for(int i = 0; i < q; ++i) {
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		--p[i][1]; --p[i][2];
	}
	for(int j = 0; j < m; ++j) {
		int t; cin >> t;
		--t;
		for(int i = q - 1; i >= 0; --i) {
			if(p[i][1] <= t && t <= p[i][2]) {
				if(p[i][0] == 1) {
					if(t == p[i][1]) t = p[i][2];
					else t = t - 1;
				}
				else {
					int l = t - p[i][1], r = p[i][2] - t;
					if(l < r) {
						t = p[i][2] - l;
					}
					else {
						t = p[i][1] + r;
					}
				}
			}
		}
		cout << v[t] << ' ';
	}
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
