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

<<<<<<< HEAD
const int mx = (int)1e5 + 10;
// *-> KISS*
int solve() {
	int n; cin >> n;
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		pq.push({b, a});
	}
	int curr = INT_MAX;
	while(!pq.empty()) {
		pair<int, int> p = pq.top(); pq.pop();
		curr = min(curr, p.ff);
		curr -= p.ss;
		if(curr < 0) {
			cout << "No"; return 0;
		}
	}
	cout << "Yes";
	return 0;
=======
// *-> KISS*
int solve() {
    int n, k, p; cin >> n >> k >> p;
    vector<ll> a(n), b(k);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    
    sort(all(a));
    sort(all(b));
    
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LLONG_MAX));
    
    for(int i = 0; i <= k; ++i) dp[n][i] = 0;
        
    for(int i = n - 1; i >= 0; --i) {
        for(int j = k - 1; j >= 0; --j) {
            dp[i][j] = max(abs(a[i] - b[j]) + abs(b[j] - p), dp[i + 1][j + 1]);
            
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    cout << dp[0][0];
    return 0;
>>>>>>> ccb2843e7994d954150ddf68592a80ec01e22a11
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
<<<<<<< HEAD
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif

=======
        #ifdef LOCAL
            cout << "##################" << '\n';
        #endif
>>>>>>> ccb2843e7994d954150ddf68592a80ec01e22a11
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
