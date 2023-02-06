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
    int n, m, d; cin >> n >> m >> d;
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];
   	
   	vector<int> a(m);
   	for(int i = 0; i < m; ++i) {
   		cin >> a[i];
   	}
   	// Kisi ek ko glt krde
   	
   	vector<int> pos(n + 1, 0);
   	for(int i = 0; i < n; ++i) {
   		pos[p[i]] = i;
   	}
   	int ans = INT_MAX;
   	for(int i = 0; i < m - 1; ++i) {
   		int p1 = pos[a[i]], p2 = pos[a[i + 1]];
   		if(p2 < p1 || (p1 + d < p2)) {
   			ans = 0;
   			break;
   		}
   		else {
   			// p1 ko left mai le jaa
   			// p2 ko right mai le jaa
   			int dif = d + 1 - (p2 - p1);
   			
   			p2 = min(n - 1, p2 + dif);
   			dif = d + 1 - (p2 - p1);
   			
   			p1 = max(0, p1 - dif);
   			dif = d + 1 - (p2 - p1);
   			if(dif == 0) {
   				ans = min(ans, pos[a[i]] - p1 + p2 - pos[a[i + 1]]);
   			}
			ans = min(ans, pos[a[i + 1]] - pos[a[i]]);			
   		}
   	}
   	cout << ans;
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