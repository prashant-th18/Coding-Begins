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
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<int>> ed(m);
    for(int i = 0; i < m; ++i) {
    	int s; cin >> s;
    	vector<int> v(s);
    	for(auto& val : v) cin >> val;
    		
    	ed[i] = v;   		
    }
    
    vector<int> ans;
    int s = 0, e = m - 1;
    while(s <= e) {
    	int mid = (s + e) >> 1;
    	vector<vector<int>> v(n + 1);
    	vector<int> in(n + 1, 0);
    	for(int i = 0; i <= mid; ++i) {
    		for(int j = 0; j < sz(ed[i]) - 1; ++j) {
    			int x = ed[i][j], y = ed[i][j + 1];
    			v[x].push_back(y);
    			in[y]++;
    		}
    	}
    	priority_queue<int, vector<int>, greater<int>> pq;
    	for(int i = 1; i <= n; ++i) {
    		if(in[i] == 0) pq.push(i);
    	}
    	vector<int> order;
    	
    	while(!pq.empty()) {
    		int t = pq.top(); pq.pop();
    		order.push_back(t);
    		
    		for(const auto& val : v[t]) {
    			--in[val];
    			if(in[val] == 0) pq.push(val);
    		}
    	}
    	if(sz(order) == n) {
    		ans = order;
    		s = mid + 1;
    	}
    	else {
    		e = mid - 1;
    	}
    }
    for(int i = 0; i < sz(ans); ++i) {
    	cout << ans[i];
    	if(i != sz(ans) - 1) cout << ' ';
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
        // cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!