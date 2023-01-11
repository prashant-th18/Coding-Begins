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
    int n, q; cin >> n >> q;
    vector<vector<int>> rank(n + 1, vector<int>(2, 1));
    vector<vector<int>> par(n + 1, vector<int>(2, -1));
    
    auto find = [&](int node, int in) {
    	vector<int> t;
    	while(par[node][in] > 0) {
    		t.push_back(node);
    		node = par[node][in];
    	}
    	for(auto val : t) par[val][in] = node;
    	return node;
    };
    
    auto unite = [&](int a, int b, int in) {
    	a = find(a, in);
    	b = find(b, in);
    	
    	if(a == b) return;
    	
    	if(rank[a] > rank[b]) swap(a, b);
    	
    	par[a][in] = b;
    	rank[b][in] += rank[a][in];
    };
    
    auto sameSet = [&](int a, int i1, int b, int i2) -> bool {
    	return find(a, i1) == find(b, i2);
    };
    
    for(int i = 0; i < q; ++i) {
    	int type; cin >> type;
    	int x, y; cin >> x >> y;
    	if(type == 1) {
    		unite(x, y, 0);
    		if(x > y) swap(x, y);
    		
    		if(find(x, 1) + 1 == find(y, 1)) {
    			par[find(x, 1)][1] = find(y, 1);
    		}
    		
    		// if(min(x, y) + 1 == max(x, y)) par[min(x, y)][1] = find(max(x, y), 1);
    	}
    	else if(type == 2) {
    		int in = find(x, 1);
    		while(in < y) {
    			int t = par[in][1] = find(in + 1, 1);
    			unite(in, t, 0);
    			in = t;
    		}
    	}
    	else {
    		// X and Y connected or not?
    		bool same = false;
    		for(int j = 0; j < 4; ++j) {
    			int one = (j & 1), two = ((j >> 1) & 1);
    			same |= sameSet(x, one, y, two);
    		}
    		if(same) cout << "YES";
    		else cout << "NO";
    		cout << '\n';
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
