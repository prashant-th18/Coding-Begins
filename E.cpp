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

int minHeightShelves(vector<vector<int>>& b, int width) {
    vector<int> dp(b.size() + 1, INT_MAX);
    dp[0] = 0;
    for (int p = 1; p <= b.size(); ++p) {
        for (int i = p, w = 0, h = 0; i > 0 && w + b[i - 1][0] <= width; --i) {
            w += b[i - 1][0];
            h = max(h, b[i - 1][1]);
            dp[p] = min(dp[p], dp[i - 1] + h);
        }
    }
    return dp.back();
}
// *-> KISS*
int solve() {
    int n, w; cin >> n >> w;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for(int i = 0; i < n; ++i) cin >> v[i][0];
    for(int i = 0; i < n; ++i) cin >> v[i][1];
    cout << minHeightShelves(v, w);
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
