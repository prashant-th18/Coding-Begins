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
    int n; cin >> n;
    map<int, int> mp;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
   	
   	int minn = 1e9;
   	
   	for(int i = n - 1; i >= 0; --i) {
   		int maxx = 1 + (mp.count(v[i] + 1) ? (mp[v[i] + 1]) : (0));
   		
   		// v[i], v[i] + maxx - 1
   		int left = v[i] - 1;
   		int right = n - (v[i] + maxx - 1);
   		
   		int temp = min(left, right);
   		int ans = temp;
   		left -= temp; right -= temp;
   		ans += left + right;
   		minn = min(minn, ans);
   		mp[v[i]] = maxx;
   	}
   	cout << minn;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    cin >> TET;
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