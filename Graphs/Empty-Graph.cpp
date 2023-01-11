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

using pii = pair<int, int>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto& val : v) cin >> val;
    
    ordered_set oset;
    for(int i = 1; i < n; ++i) {
        oset.insert({v[i], i});
    }
    
    auto get = [&](int in) {
        if(in >= sz(oset)) return (int)1e9;
        
        return oset.find_by_order(in)->ff;
    };
    int ans = 0;
    
    for(int i = 0; i < n - 1; ++i) {
        oset.erase({v[i + 1], i + 1});
        int temp = (int)2e9;
        
        // Three cases
        // 1. Don't apply operation on i, i + 1
        // 2. Apply operation of minimum of (i, i + 1)
        // 3. Apply operation on both
        
        ans = max(ans, max(min(min(v[i], v[i + 1]), 2 * get(k)), 
            max(min(max(v[i], v[i + 1]), 2 * get(k - 1)), 
                (k >= 2) ? (min((int)1e9, 2 * get(k - 2))) : (0))));
        
        oset.insert({v[i], i});
    }
    cout << ans;
    oset.clear();
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