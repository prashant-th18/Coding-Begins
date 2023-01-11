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

const int N = 26;
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    
    vector<vector<int>> v(n);
    vector<int> in(n, 0);
    for(int i = 0; i < m; ++i) {
    	int a, b; cin >> a >> b;
    	--a, --b;
    	v[a].push_back(b);
    	in[b]++;
    }
    
    // Cycle present
    // answer -1
    
    vector<vector<int>> dp(n, vector<int>(N, 0));
    
    int distinct = 0;
    queue<int> q;
    
    for(int i = 0; i < n; ++i) {
    	if(in[i] == 0) {
    		q.push(i);
    		dp[i][s[i] - 'a'] = 1;
    	}
    }
    
    while(!q.empty()) {
    	int t = q.front(); q.pop();
    	++distinct;
    	
    	for(const auto& val : v[t]) {
    		for(int i = 0; i < 26; ++i) {
    			dp[val][i] = max(dp[val][i], (i == (s[val] - 'a')) + 
    											dp[t][i]);
    		}
    		--in[val];
    		if(in[val] == 0) q.push(val);
    	}
    }
    
    if(distinct != n) {
    	cout << -1; return 0;
    }
    
    int maxx = 0;
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < 26; ++j) maxx = max(maxx, dp[i][j]);
    }
	cout << maxx;
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