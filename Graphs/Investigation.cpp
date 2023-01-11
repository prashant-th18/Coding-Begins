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
struct node {
	ll f, s;
	
	bool operator<(const node& other) const {
		if(f != other.f) return f < other.f;
		return s < other.s;
	}
};
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pll>> v(n + 1);
    for(int i = 0; i < m; ++i) {
    	ll a, b, c; cin >> a >> b >> c;
    	v[a].push_back({b, c});
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
    for(int i = 1; i <= n; ++i) {
    	dp[i][0] = LLONG_MAX;
    	dp[i][1] = 0;
    	dp[i][2] = LLONG_MAX;
    	dp[i][3] = LLONG_MIN;
    }
    
    dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = dp[1][3] = 0;
    
    set<pll> pq;
    
    pq.insert({0, 1});
    
    auto handle = [&](ll a, ll b) -> void {
    	pll p = pair(a, b);
    	if(pq.count(p)) pq.erase(p);
    };
    
    
    while(!pq.empty()) {
    	pll p = *(pq.begin()); pq.erase(pq.begin());
    	
    	ll node = p.ss, dis = p.ff;
    	if(dp[node][0] < dis) continue;
    	
    	for(const auto& val : v[node]) {
    		ll adj = val.ff, w = val.ss;
    		
    		if(dis + w < dp[adj][0]) {
    			handle(dp[adj][0], adj);
    			dp[adj][0] = dis + w;
    			dp[adj][1] = dp[node][1];
    			dp[adj][2] = dp[node][2] + 1;
    			dp[adj][3] = dp[node][3] + 1;
    			pq.insert(pair{dis + w, adj});
    		}
    		else if(dis + w == dp[adj][0]) {
    			// handle(dp[adj][0], adj);
    			dp[adj][1] = (dp[adj][1] + dp[node][1]) % MOD;
    			dp[adj][2] = min(dp[adj][2], dp[node][2] + 1);
    			dp[adj][3] = max(dp[adj][3], dp[node][3] + 1);
    			// pq.insert(pair{dis + w, adj});
    		}
    	}
    }
    cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << ' ' << dp[n][3];
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
