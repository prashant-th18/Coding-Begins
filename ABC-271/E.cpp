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
    int n, m, k; cin >> n >> m >> k;
	vector<vector<pll>> v(n + 1);
	vector<array<ll, 3>> order(m);
	for(int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back(pll(b, c));
		order[i] = {a, b, c};
	}
	vector<int> p(k);
	for(int i = 0; i < k; ++i) cin >> p[i];
	vector<ll> dp(n + 1, LLONG_MAX);
	dp[n] = 0;
	// -1 means not possible
	for(int i = k - 1; i >= 0; --i) {
		array<ll, 3> t = order[p[i] - 1];
		int a = t[0], b = t[1];
		ll c = t[2];
		if(dp[b] != LLONG_MAX) {
			dp[a] = min(dp[a], dp[b] + c);
		}
	}
	cout << (dp[1] != LLONG_MAX ? dp[1] : -1);
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
