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
    int n, k; cin >> n >> k;
    vector<int> rank(n + 1, 1);
    vector<int> par(n + 1, -1);
    
    auto find = [&](int node) {
    	vector<int> t;
    	while(par[node] > 0) {
    		t.push_back(node);
    		node = par[node];
    	}
    	for(auto val : t) par[val] = node;
    	return node;
    };
    
    auto un = [&](int a, int b) {
    	a = find(a), b = find(b);
    	if(a == b) return;
    	
    	if(rank[a] > rank[b]) swap(a, b);
    	
    	par[a] = b; rank[b] += rank[a];
    };
    
    vector<array<int, 3>> q(k);
    for(int i = 0; i < k; ++i) cin >> q[i][0] >> q[i][1] >> q[i][2];
    	
    sort(all(q), [&](array<int, 3>& a, array<int, 3>& b) {
    	return a[2] < b[2];
    });

	for(int i = 0; i < k; ++i) {
		un(q[i][0], q[i][1]);
		if(rank[find(q[i][0])] == n) {
			cout << q[i][2];
			return 0;
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
