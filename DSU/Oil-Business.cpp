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
	ll n, m, s; cin >> n >> m >> s;
	
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
    
    vector<array<int, 4>> q(m);
    for(int i = 0; i < m; ++i) cin >> q[i][0] >> q[i][1] >> q[i][2], q[i][3] = i;
    	
    sort(all(q), [&](array<int, 4>& a, array<int, 4>& b) {
    	return a[2] > b[2];
    });

    vector<pair<ll, ll>> t;
    for(int i = 0; i < m; ++i) {
        int a = find(q[i][0]);
        int b = find(q[i][1]);
        
        if(a == b) {
            t.push_back({q[i][2], q[i][3]});
        }
        else {
            un(a, b);
        }
    }
    
    vector<int> ans;
    for(ll i = sz(t) - 1, sum = 0; i >= 0; --i) {
        sum += t[i].ff;
        if(sum <= s) ans.push_back(t[i].ss);
        else break;
    }
    sort(all(ans));
    cout << sz(ans) << '\n';
    for(auto val : ans) cout << val + 1 << ' ';
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
