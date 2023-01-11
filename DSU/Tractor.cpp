// #include <cstdio>
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
	freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);
    int n; cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n, 0));
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		cin >> v[i][j];
    	}
    }
    
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(n, {-1, -1}));
    vector<vector<ll>> rank(n, vector<ll>(n, 1));
    decltype(rank) cost(n, vector<ll>(n, 0));
    
    auto find = [&](int i, int j) {
    	vector<pair<int, int>> t;
    	while(par[i][j].ff >= 0) {
    		t.push_back({i, j});
    		int t1 = i, t2 = j;
    		i = par[t1][t2].ff;
    		j = par[t1][t2].ss;
    		// assert(i >= 0 && j >= 0);
    	}
    	
    	for(auto val : t) par[val.ff][val.ss] = {i, j};
    	return make_pair(i, j);
    };
    
    auto unite = [&](int i1, int j1, int i2, int j2) {
    	auto p1 = find(i1, j1), p2 = find(i2, j2);
    	
    	if(p1 == p2) return;
    	
    	if(rank[p1.ff][p1.ss] > rank[p2.ff][p2.ss]) swap(p1, p2);
    	
    	par[p1.ff][p1.ss] = p2;
    	rank[p2.ff][p2.ss] += rank[p1.ff][p1.ss];
    	
    	cost[p2.ff][p2.ss] = max(cost[p2.ff][p2.ss], max(cost[p1.ff][p1.ss], abs(v[i1][j1] - v[i2][j2])));
    };
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    vector<array<ll, 5>> ans;
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		for(int k = 0; k < 4; ++k) {
    			int ni = i + dx[k], nj = j + dy[k];
    			if(0 <= ni && ni < n && 0 <= nj && nj < n) {
    				ans.push_back({abs(v[i][j] - v[ni][nj]), i, j, ni, nj});
    			}
    		}
    	}
    }
    
    sort(all(ans), [&](array<ll, 5>& a, array<ll, 5>& b) {
    	return a[0] < b[0];
    });

    for(int i = 0; i < sz(ans); ++i) {
    	array<ll, 5> t = ans[i];
    	ll c = t[0], i1 = t[1], j1 = t[2], i2 = t[3], j2 = t[4];
    	
    	auto p1 = find(i1, j1);
    	auto p2 = find(i2, j2);
    	
    	if(p1 == p2) continue;
    	else {
    		unite(i1, j1, i2, j2);
    		p1 = find(i1, j1);
    		if((rank[p1.ff][p1.ss]) >= (n * n + 1) / 2) {
    			cout << cost[p1.ff][p1.ss];
    			// cout << "OUT\n";
    			return 0;
    		} 
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
