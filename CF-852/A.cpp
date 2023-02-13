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
    vector<int> e(n + 1);
    for(int i = 0; i < n; ++i) {
    	cin >> e[i + 1];
    }
    vector<vector<int>> v(n + 1);
    vector<int> in(n + 1, 0);
    for(int i = 0; i < m; ++i) {
    	int t1, t2; cin >> t1 >> t2;
    	v[t1].push_back(t2);
    	++in[t2];
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
    	if(in[i] == 0) {
    		q.push(i);
    	}
    }
    int ans = 0;
    while(true) {
    	queue<int> keep;
    	int c = 0;
    	while(!q.empty()) {
    		int t = q.front(); q.pop();
    		if(e[t] == 0) {
    			// This is "main"
    			keep.push(t);
    			for(const auto& val : v[t]) {
    				if(e[val] == 0) {
    					--in[val];
    					if(in[val] == 0) q.push(val);
    				}
    			}
    		}
    		else {
    			++c;
    			for(const auto& val : v[t]) {
    				--in[val];
    				if(in[val] == 0) {
    					q.push(val);
    				}
    			}
    		}
    	}
    	if(c) {
    		++ans;
    	}
    	
    	
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    //cin >> TET;
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