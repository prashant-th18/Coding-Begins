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
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<pll>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		ll a, b, c; cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	vector<multiset<ll>> dp(n + 1);
	multiset<pll> st;
	dp[1].insert(0);
	st.insert({0, 1});
	
	while(!st.empty()) {
		pll p = *(st.begin());
		st.erase(st.begin());
		
		ll node = p.ss, dis = p.ff;
		for(const auto& val : v[node]) {
			ll nd = val.ss + dis;
			ll adj = val.ff;
			
			if(distance(begin(dp[adj]), dp[adj].lower_bound(nd)) >= k) {
				// No need to insert {nd, adj}
			}
			else {
				if(sz(dp[adj]) == k) {
					ll last = *(dp[adj].rbegin());
					dp[adj].erase(dp[adj].find(last));
					
					auto it = st.find({last, adj});
					assert(it != st.end());
					st.erase(it);
				}
				st.insert({nd, adj});
				dp[adj].insert(nd);
			}
		}
	}
	assert(sz(dp[n]) >= k);
	for(int i = 0; i < k; ++i) {
		cout << *(dp[n].begin()) << ' ';
		dp[n].erase(dp[n].begin());
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