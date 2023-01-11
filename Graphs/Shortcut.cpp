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
	freopen("shortcut.in", "r", stdin);
	freopen("shortcut.out", "w", stdout);
    ll n, m, t; cin >> n >> m >> t;
    vector<ll> c(n + 1);
    for(int i = 0; i < n; ++i) cin >> c[i + 1];
    // c[i] -> Number of cows in node "i"
    
    vector<vector<pll>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		ll a, b, cost; cin >> a >> b >> cost;
		v[a].push_back({b, cost});
		v[b].push_back({a, cost});
	}
	
	vector<pll> par(n + 1, {n + 2, 0});
	vector<ll> dist(n + 1, LLONG_MAX);
	
	par[1].ff = -1;
	dist[1] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	
	pq.push({0, 1});
	while(!pq.empty()) {
		pll p = pq.top(); pq.pop();
		ll node = p.ss, dis = p.ff;
		
		if(dist[node] < dis) continue;
		
		for(const auto& val : v[node]) {
			ll ndis = dis + val.ss;
			if(ndis < dist[val.ff]) {
				par[val.ff] = {node, val.ss};
				dist[val.ff] = ndis;
				pq.push({ndis, val.ff});
			}
			else if(ndis == dist[val.ff] && node < par[val.ff].ff) {
				par[val.ff] = {node, val.ss};
				pq.push({ndis, val.ff});
			}
		}
	}
	
	vector<ll> here(n + 1, 0);
	for(int i = 2; i <= n; ++i) {
		ll node = i, sum = 0, how = c[i];
		while(node != 1) {
			here[par[node].ff] += how;
			node = par[node].ff;
		}
	}
	
	ll total = 0;
	for(int i = 1; i <= n; ++i) total += dist[i] * c[i];
		
	ll dec = 0;
	for(int i = 2; i <= n; ++i) {
		// 1 to i
		
		ll rem = total - here[i] * dist[i];
		rem -= dist[i] * c[i];
		
		ll op = rem + min(dist[i] * c[i], t * c[i]) + 
				 min(here[i] * dist[i], here[i] * t);
		
		
		if(op < total) {
			dec = max(dec, total - op);
		}
	}
	cout << dec;
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
