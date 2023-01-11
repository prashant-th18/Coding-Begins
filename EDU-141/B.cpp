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
    int maxx = n * n, minn = 1;
    vector<int> order;
    for(int i = 0; i < n * n; ++i) {
        if(i % 2 == 0) order.push_back(maxx--);
        else order.push_back(minn++);
    }
    reverse(all(order));
    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        if(i & 1) {
            for(int j = n - 1; j >= 0; --j) {
                v[i][j] = order.back(); order.pop_back();
            }
        }
        else {
            for(int j = 0; j < n; ++j) {
                v[i][j] = order.back(); order.pop_back();
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cout << v[i][j] << ' ';
        cout << '\n';
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
