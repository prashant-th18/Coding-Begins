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
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
    ll n, m, c; cin >> n >> m >> c;
    vector<ll> cost(n + 1, 0);
    vector<vector<pair<ll, ll>>> v(n + 1);
    vector<int> in(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
    	cin >> cost[i];
    }
    for(int i = 0; i < c; ++i) {
    	ll a, b, x; cin >> a >> b >> x;
    	v[a].push_back({b, x});
    	in[b]++;
    }
    queue<pair<ll, ll>> q;
    for(int i = 1; i <= n; ++i) {
    	if(in[i] == 0) {
    		q.push({i, cost[i]});
    	}
    }
    vector<int> ans(n + 1, 0);
    while(!q.empty()) {
    	pair<ll, ll> t = q.front(); q.pop();
    	ans[t.ff] = t.ss;
    	
    	for(const auto& val : v[t.ff]) {
    		--in[val.ff];
    		cost[val.ff] = max(cost[val.ff], t.ss + val.ss);
    		if(in[val.ff] == 0) {
    			q.push({val.ff, cost[val.ff]});
    		}
    	}
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
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
        // cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
