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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int maxx = (int)1e6;
const int MAXX = (int)5001;
ll dp[MAXX][MAXX];
vector<int> v;
vector<int> mp[2 * maxx + 1];

// *-> KISS*
int solve() {
	freopen("threesum.in", "r", stdin);
	freopen("threesum.out", "w", stdout);
	int n, q; cin >> n >> q;
	v.assign(n, 0);
	for(int i = 0; i < 2 * maxx + 1; ++i) mp[i] = vector<int>();
	for(ll i = 0; i < n; ++i) {
		cin >> v[i];
		mp[v[i] + maxx].push_back(i);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) dp[i][j] = 0;
	}
	for(int i = 0; i < n; ++i) {
		gp_hash_table<int,int> g({}, {}, {}, {}, {1<<13});
		for(int j = i + 1; j < n; ++j) {
			int val = -(v[i] + v[j]);
			auto it = g.find(val);
			if(it != g.end()) dp[i][j] += it -> second;
			g[v[j]]++;
		}
	}
	for(int l = 3; l <= n; ++l) {
		for(int i = 0; i <= n - l; ++i) {
			int j = i + l - 1;
			dp[i][j] += dp[i][j - 1] - dp[i + 1][j - 1] + dp[i + 1][j];
		}
	}
	while(q--) {
		int a, b; cin >> a >> b;
		--a; --b;
		cout << dp[a][b];
		if(q) cout << '\n';
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
