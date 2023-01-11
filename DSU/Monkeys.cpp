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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) {
    	cin >> v[i].ff >> v[i].ss;
    }
    
    auto cpy = v;
    
    vector<bool> rank(n + 1, false);
    vector<int> par(n + 1, -1);
    vector<vector<int>> li(n + 1);
    vector<int> ans(n + 1, -1);
    
    for(int i = 1; i <= n; ++i) li[i].push_back(i);
    	
    rank[1] = true;

	
    
    auto find = [&](int node) {
    	vector<int> t;
    	while(par[node] > 0) {
    		t.push_back(node);
    		node = par[node];
    	}
    	
    	for(auto val : t) par[val] = node;
    	
    	return node;
    };
    
    auto unite = [&](int a, int b, int ti = -1) {
    	a = find(a), b = find(b);
    	if(a == b) return;
    
	    if(rank[a]) {
    		// a is visited
    		int p = b;
    		if(rank[p]) {}
    		else {
    			for(auto val : li[p]) rank[val] = true, ans[val] = ti;
    				
    			li[p].clear();
    		}
    	}
    	else {
    		// a is not visited
    		int p = a;
    		// b = find(b);
    		
    		if(rank[b]) {
    			for(auto val : li[p]) rank[val] = true, ans[val] = ti;
    				
    			li[p].clear();
    		}
    		else {
    			if(sz(li[a]) > sz(li[b])) swap(a, b);
    	
		    	for(auto val : li[a]) par[val] = b;
		    		
		    	for(auto val : li[a]) li[b].push_back(val);
		    		
		    	li[a].clear();
    		}
    	}
    };
    
    vector<pair<int, int>> query(m);
    for(int i = 0; i < m; ++i) {
    	cin >> query[i].ff >> query[i].ss;
    	if(query[i].ss == 1) {
    		cpy[query[i].ff - 1].ff = -1;
    	}
    	else {
    		cpy[query[i].ff - 1].ss = -1;
    	}
    }
    
    for(int i = 0; i < n; ++i) {
    	if(cpy[i].ff != -1) unite(i + 1, cpy[i].ff);
    	if(cpy[i].ss != -1) unite(i + 1, cpy[i].ss);
    }
        
    for(int i = m - 1; i >= 0; --i) {
    	int a = query[i].ff;
    	int b = (query[i].ss == 1) ? (v[a - 1].ff) : (v[a - 1].ss);
    	
    	unite(a, b, i);
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
        cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
