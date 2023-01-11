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
    vector<int> par(n + 1, -1);
    vector<int> len(n + 1, 0);
    
    auto find = [&](int node) -> pair<int, int> {
    	vector<int> t;
    	while(par[node] > 0) {
    		t.push_back(node);
    		node = par[node];
    	}
    	
    	ll length = 0;
    	
    	for(int i = sz(t) - 1; i >= 0; --i) {
    		len[t[i]] += (len[par[t[i]]]);
    		par[t[i]] = node;
    	}
    	
    	return {node, (sz(t) == 0) ? (0) : (len[t[0]])};
    };
    
    for(int i = 0; i < m; ++i) {
    	int t; cin >> t;
    	if(t == 1) {
    		int x, y; cin >> x >> y;
    		auto p = find(y);
    		par[x] = y;
    		len[x] = p.ss + 1;
    	}
    	else {
    		int x; cin >> x;
    		cout << (find(x).ss) << '\n';
    	}
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

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	return 0;
}
// -> Keep It Simple Stupid!
