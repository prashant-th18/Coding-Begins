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
    vector<int> rank(n + 1, 1);
    vector<int> par(n + 1, -1);
    auto find = [&](int a) {
    	vector<int> t;
    	while(par[a] != -1) {
    		t.push_back(a);
    		a = par[a];
    	}
    	for(auto val : t) par[val] = a;
    	return a;
    };
    auto un = [&](int a, int b) {
    	a = find(a), b = find(b);
    	if(a == b) return;
    	if(rank[a] > rank[b]) {
    		rank[a] += rank[b];
    		par[b] = a;
    	}
    	else {
    		rank[b] += rank[a];
    		par[a] = b;
    	}
    };
    while(q--) {
    	int t, a, b; cin >> t >> a >> b;
    	if(t == 0) {
    		un(a, b);
    	}
    	else {
    		if(find(a) == find(b)) cout << 1;
    		else cout << 0;
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