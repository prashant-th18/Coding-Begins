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

int n1, n2;
int m1, m2;
vector<vector<int>> v1, v2;
vector<vector<bool>> dp1, dp2;
vector<int> in1, in2;
void topo(vector<int>& in, vector<vector<int>>& v, vector<vector<bool>>& dp, int n, int m) {
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		if(in[i] == 0) {
			q.push(i);
		}
	}
	
	vector<int> order;
	while(!q.empty()) {
		int t = q.front(); q.pop();
		order.push_back(t);
		
		for(const auto& val : v[t]) {
			--in[val];
			if(in[val] == 0) q.push(val);
		}
	}
	
	dp[n][0] = true;
	for(int i = sz(order) - 1; i >= 0; --i) {
		int node = order[i];
		
		for(int j = 1; j <= m; ++j) {
			for(const auto& val : v[node]) {
				dp[node][j] = dp[node][j] | dp[val][j - 1];
			}
		}
	}
}
// *-> KISS*
int solve() {
    cin >> n1 >> n2;
    cin >> m1 >> m2;
    v1.assign(n1 + 1, vector<int>());
    v2.assign(n2 + 1, vector<int>());
    dp1.assign(n1 + 1, vector<bool>(2000 + 1, false));
    dp2.assign(n2 + 1, vector<bool>(2000 + 1, false));
    in1.assign(n1 + 1, 0);
    in2.assign(n2 + 1, 0);
    
    for(int i = 0; i < m1; ++i) {
    	int a, b; cin >> a >> b;
    	in1[b]++;
    	v1[a].push_back(b);
    }
    
    for(int i = 0; i < m2; ++i) {
    	int a, b; cin >> a >> b;
    	in2[b]++;
    	v2[a].push_back(b);
    }
    
    // dp1[i][j]
    // Is it possible to reach n1 from index i in j steps
    // Similiar for dp2[i][j]
    
    topo(in1, v1, dp1, n1, m1);
    topo(in2, v2, dp2, n2, m2);
    int q; cin >> q;
    while(q--) {
    	int t; cin >> t;
    	bool flag = false;
    	for(int z = 0; z <= t; ++z) {
	    	if(dp1[1][z] && dp2[1][t - z]) flag = true;
    	}
    	if(flag) cout << "Yes";
    	else cout << "No";
    	cout << '\n';
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
