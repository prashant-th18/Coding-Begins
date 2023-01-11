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
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<vector<int>> v(n - 1, vector<int>(3, 0));
    for(int i = 0; i < n - 1; ++i) {
    	cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    
    sort(all(v), [&](vector<int>& a, vector<int>& b) {
    	return a[2] > b[2];
    });
    
    vector<array<int, 3>> query(q);
    vector<int> ans(q);
    for(int i = 0; i < q; ++i) {
    	cin >> query[i][0] >> query[i][1];
    	query[i][2] = i;
    }
    
    sort(all(query), [&](array<int, 3> &a, array<int, 3>& b) {
    	return a[0] > b[0];
    });
    
    vector<int> par(n + 1, -1), rank(n + 1, 1);
    
    auto find = [&](int node) {
    	vector<int> t;
    	while(par[node] > 0) {
    		t.push_back(node);
    		node = par[node];
    	}
    	
    	for(auto val : t) par[val] = node;
    	return node;
    };
    
    auto unite = [&](int a, int b) {
    	a = find(a), b = find(b);
    	
    	if(a == b) return;
    	if(rank[a] > rank[b]) swap(a, b);
    	
    	rank[b] += rank[a];
    	par[a] = b;
    };    
    
    int i = 0, j = 0;
    while(j < q) {
    	while(i < n - 1 && v[i][2] >= query[j][0]) {
    		unite(v[i][0], v[i][1]);
    		++i;
    	}
    	
    	ans[query[j][2]] = rank[find(query[j][1])] - 1;
    	++j;   	
    }
    for(auto val : ans) cout << val << '\n';
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
