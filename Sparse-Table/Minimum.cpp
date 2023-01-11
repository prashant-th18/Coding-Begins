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

const int K = 25;
int lg(int number) {
  return 31 - __builtin_clz(number);
}
// *-> KISS*
int solve() {
    
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    
    vector<vector<int>> rmq(K, vector<int>(n, INT_MAX));
	for(int i = 0; i < n; ++i) {
		rmq[0][i] = v[i];
	}
	
	for(int i = 1; i < K; ++i) {
		for(int j = 0; j <= n - (1 << i); ++j) {
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		}
	}
	
	// Initialization Done
	
	while(q--) {
		int a, b; cin >> a >> b;
		--a; --b;
		
		int dif = b - a + 1;
		// 31 - __builtin_clz(dif)
		
		int p = lg(dif);
		cout << min(rmq[p][a], rmq[p][b - (1 << p) + 1]) << '\n';
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