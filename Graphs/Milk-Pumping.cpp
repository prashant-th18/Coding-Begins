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

struct node {
	ll flow, cost, val;
	
	bool operator<(const node& other) const {
		ll a = flow * other.cost;
		ll b = cost * other.flow;
		if(a != b) return a > b;
		
		return val > other.val;
	}
};
// *-> KISS*
int solve() {
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);
	int n, m; cin >> n >> m;
    vector<vector<array<ll, 3>>> v(n + 1);
    for(int i = 0; i < m; ++i) {
    	ll a, b, c, d; cin >> a >> b >> c >> d;
    	v[a].push_back({b, c, d});
    	v[b].push_back({a, c, d});
    }
    
    // This Code is although giving AC,
	// But I think, it can break for some test case
    
    // vector<ll> cost(n + 1, 1), flow(n + 1, 0);
    // flow[1] = 1000;
    // cost[1] = 0;
    // set<node> st; // flow, cost, val
    // st.insert({1000, 0, 1});
    
    // while(!st.empty()) {
    // 	node t = *(st.begin());
    // 	st.erase(st.begin());
    	
    // 	ll f = t.flow, c = t.cost, val = t.val;
    	
    // 	if(f * cost[val] < c * flow[val]) continue;
    	
    // 	for(const auto& value : v[val]) {
    // 		ll betweenFlow = min(f, value[2]);
    // 		ll betweenCost = c + value[1];
    // 		ll newNode = value[0];
    		
    // 		ll& nFlow = flow[newNode];
    // 		ll& nCost = cost[newNode];
    		
    // 		if(betweenFlow * nCost > nFlow * betweenCost) {
    // 			nFlow = betweenFlow;
    // 			nCost = betweenCost;
    // 			st.insert({nFlow, nCost, newNode});
    // 		}
    // 	}
    // }
    
    // ll ans = (double)flow[n] / cost[n] * (1000000LL);
    // cout << ans;
    
    auto ans = [&](int f) -> int {
    	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    	vector<ll> cost(n + 1, 1e9);
    	// flow[1] = f;
    	cost[1] = 0;
    	pq.push({0, 1});
    	while(!pq.empty()) {
    		pair<int, int> t = pq.top(); pq.pop();
    		
    		if(cost[t.ss] < t.ff) continue;
    		
    		for(auto val : v[t.ss]) {
    			int node = val[0],
    				c = val[1],
    				nf = val[2];
    				
    			if(nf < f) continue;
    			
    			if(cost[t.ss] + c < cost[node]) {
    				cost[node] = cost[t.ss] + c;
    				pq.push({cost[node], node});
    			}
    		}
    	}
    	return cost[n];
    };
    
    ll flow = 0, cost = 1;
    for(int i = 1; i <= 1000; ++i) {
    	ll nCost = ans(i);
    	
    	if(i * cost > flow * nCost) {
    		cost = nCost;
    		flow = i;
    	}
    }
    
    ll res = (double)flow / cost * (1000000LL);
    cout << res;   
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