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

using pii = pair<int, int>;
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    int minSteps = 1e9;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, n});
    vector<bool> vis(1e5 + 1, false);
    vis[n] = true;
    while(!q.empty()) {
    	pii p = q.top(); q.pop();
    	if(p.ss == m) {
    		minSteps = p.ff;
    		break;
    	}
    	else if(p.ss > m) {
    		p.ff++;
    		p.ss--;
    		if(p.ss > 0 && !vis[p.ss]) {
    			q.push(p);
    			vis[p.ss] = true;
    		}
    	}
    	else {
    		if(!vis[p.ss * 2]) {
    			vis[p.ss * 2] = true;
    			q.push({p.ff + 1, p.ss * 2});
    		}
    		if(p.ss - 1 > 0 && !vis[p.ss - 1]) {
    			vis[p.ss - 1] = true;
    			q.push({p.ff + 1, p.ss - 1});
    		}
    	}
    }
    cout << minSteps;
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
