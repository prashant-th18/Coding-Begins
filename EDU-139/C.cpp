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

bool get(vector<string>& v) {
	int n = v[0].size();
	vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(2, vector<bool>(3, false)));
	
	dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = true;
	dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = true;
	
	for(int i = n - 1; i >= 0; --i) {
		vector<int> in;
		if(v[0][i] == 'B') in.push_back(0);
		if(v[1][i] == 'B') in.push_back(1);
		
		if(v[0][i] == 'B') dp[i][0][1] = dp[i][0][1] | (dp[i + 1][0][0] && v[1][i] == 'B');
		if(v[1][i] == 'B') dp[i][1][2] = dp[i][1][2] | (dp[i + 1][1][0] && v[0][i] == 'B');
		
		if(v[0][i] == 'B') {
			if(sz(in) == 1) dp[i][0][0] = dp[i + 1][0][0];
			else {
				dp[i][0][0] = dp[i][1][2];
			}
		}
		
		if(v[1][i] == 'B') {
			if(sz(in) == 1) dp[i][1][0] = dp[i + 1][1][0];
			else {
				dp[i][1][0] = dp[i][0][1];
			}
		}
	}
	
	bool flag = false;
	
	if(v[0][0] == 'B') flag |= dp[0][0][0];
	if(v[1][0] == 'B') flag |= dp[0][1][0];
	
	return flag;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<string> v(2);
    cin >> v[0] >> v[1];
    
    if(get(v)) {
    	cout << "YES";
    }
    else {
    	reverse(all(v[0]));
    	reverse(all(v[1]));
    	if(get(v)) {
    		cout << "YES";
    	}
    	else {
    		cout << "NO";
    	}
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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
