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
    int n, m, l; cin >> n >> m >> l;
	vector<int> a(n), b(m), c(l);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < m; ++i) cin >> b[i];
	for(int i = 0; i < l; ++i) cin >> c[i];
	sort(all(a)); sort(all(b)); sort(all(c));
	vector<int> v;
	v.insert(v.end(), all(a));
	v.insert(v.end(), all(b));
	v.insert(v.end(), all(c));
	vector<int> lis;
	for(int i = 0; i < sz(v); ++i) {
		auto it = upper_bound(all(lis), v[i]);
		if(it == lis.end()) lis.push_back(v[i]);
		else *it = v[i];
	}
	cout << sz(v) - sz(lis);
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
