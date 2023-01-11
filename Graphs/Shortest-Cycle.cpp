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

int ans = 1e9;
vector<int> dis;
vector<bool> vis;

int shortestCycle(vector<vector<int>>& v) {
	int n = v.size() - 1;
	vector<int> dist(n + 1, 1e9);
	for(int i = 1; i <= n; ++i) {
		dist.assign(n + 1, 1e9);
		queue<int> q; 
		q.push(i);
		dist[i] = 0;
		vector<int> par(n + 1, -1);
		while(!q.empty()) {
			int t = q.front(); q.pop();
			
			for(auto & val : v[t]) {
				if(dist[val] == 1e9) {
					q.push(val);
					par[val] = t;
					dist[val] = dist[t] + 1;
				}
				else if(val != par[t] && t != par[val]) {
					ans = min(ans, dist[val] + dist[t] + 1);
				}
			}
		}
	}
	if(ans == 1e9) ans = -1;
	return ans;
}

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<ll> v;
    vector<ll> pre(64, 0);
    for(int i = 0; i < n; ++i) {
    	ll t; cin >> t;
    	if(t != 0) {
			v.push_back(t);
		    for(int j = 0; j < 63; ++j) {
	    		pre[j] += ((v.back() >> j) & 1);
	    	}
	    }
    }
    
    for(int i = 0; i < 64; ++i) {
    	if(pre[i] >= 3) {
    		cout << 3; return 0;
    	}
    }
    n = v.size();
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n; ++i) {
    	for(int j = i + 1; j < n; ++j) {
    		if((v[i] & v[j]) != 0) {
    			adj[i + 1].push_back(j + 1);
    			adj[j + 1].push_back(i + 1);
    		}
    	}
    }
    cout << shortestCycle(adj);
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