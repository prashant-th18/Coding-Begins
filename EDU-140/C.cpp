#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 998244353;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll mul(ll a, ll b) {
	return a * b % MOD;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; ++i) {
    	vector<int> t(n - i);
    	for(auto& val : t) cin >> val;
    	
    	v[i] = t;
    }
    vector<vector<vector<vector<ll>>>> dp(n + 1, vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(3)));
    
    for(int i = 0; i <= n; ++i) {
    	for(int j = 0; j <= n; ++j) {
    		for(int k = 0; k < 3; ++k) {
    			if(k == 1) {
    				dp[i][j][k].assign(2, 0);
    			}
    			else {
    				dp[i][j][k].assign(1, 0);
    			}
    		}
    	}
    }
    
    // dp[i][j][k][l]
    
    // Range [i .. j]
    // Condition k (a_ij)
    // l says about whether 0 or 1
    
    auto fun = [&](int i, int j) {
    	ll res = 0;
    	int op = v[i][j - i];
    	if(op != 1) return dp[i][j][op][0];
    	else {
    		return add(dp[i][j][1][0], dp[i][j][1][1]);
    	}
    	
    };
    
    for(int l = 1; l <= n; ++l) {
    	for(int i = 0; i <= n - l; ++i) {
    		int op = v[i][l - 1];
    		int j = i + l - 1;
    		
    		if(l == 1) {
    			if(op != 2) {
    				dp[i][j][0][0] = 2;
    				dp[i][j][1][0] = dp[i][j][1][1] = 1;
    				dp[i][j][2][0] = 0;
    			}
    			else {
    				// All zero
    			}
    		}
    		else {
    			if(op == 0) {
    				bool zero = true, one = true;
    				for(int k = i; k < j; ++k) {
    					dp[i][j][0][0] = add(dp[i][j][0][0], mul(fun(i, k), fun(k + 1, j)));
    					zero &= (dp[i][k][1][0] && dp[k + 1][j][1][0]);
    					one &= (dp[i][k][1][1] && dp[k + 1][j][1][1]);
    					
    					
    					ll op = 0;
    					// op = add(op, mul(dp[i][k][0][0], dp[k + 1][j][2][0]));
    					op = add(op, mul(dp[i][k][1][0], dp[k + 1][j][1][1]));
    					op = add(op, mul(dp[i][k][1][1], dp[k + 1][j][1][0]));
    					dp[i][j][2][0] = add(dp[i][j][2][0], op);
    				}
    				
    				dp[i][j][1][0] = zero;
    				dp[i][j][1][1] = one;
    				
    				
    				
    				
    				
    				
    				
    				
    				
    				
    				
    				
    				
    			}
    			else if(op == 1) {
    				bool zero = true, one = true;
    				for(int k = i; k < j; ++k) {
    					zero &= (dp[i][k][1][0] && dp[k + 1][j][1][0]);
    					one &= (dp[i][k][1][1] && dp[k + 1][j][1][1]);
    				}
    				
    				dp[i][j][2][0] = 0;
    				
    				dp[i][j][1][0] = zero;
    				dp[i][j][1][1] = one;
    				
    				dp[i][j][0][0] = add(dp[i][j][1][0], dp[i][j][1][1]);
    			}
    			else {
    				for(int k = i; k < j; ++k) {    					
    					// ll op = mul(dp[i][k][2][0], dp[k + 1][j][0][0]);
    					// op = add(op, mul(dp[i][k][0][0], dp[k + 1][j][2][0]));
    					ll op = 0;
    					op = add(op, mul(dp[i][k][1][0], dp[k + 1][j][1][1]));
    					op = add(op, mul(dp[i][k][1][1], dp[k + 1][j][1][0]));
    					dp[i][j][2][0] = add(dp[i][j][2][0], op);
    				}
    				dp[i][j][0][0] = dp[i][j][2][0];
    			}
    		}
    		// cout << dp[i][j][o]
    	}
    }
    ll ans = 0;
    int i = 0, j = n - 1;
    int op = v[0][n - 1];
    if(op == 0 || op == 2) {
    	ans = dp[i][j][op][0];
    }
    else {
    	ans = add(dp[i][j][1][0], dp[i][j][1][1]);
    }
    cout << ans;
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