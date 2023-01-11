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
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<pll> v(n);
	map<int, int> ind;
	for(int i = 0; i < n; ++i) cin >> v[i].ff >> v[i].ss, ind[v[i].ff] = ind[v[i].ss] = i;
	vector<pll> more, less;
	for(int i = 0; i < n; ++i) {
		if(v[i].ff < v[i].ss) less.push_back(v[i]);
		else more.push_back(v[i]);
	}
	sort(less.begin(), less.end(), [&](pll a, pll b) {
		return a.ss > b.ss;
	});
	sort(more.begin(), more.end(), [&](pll a, pll b) {
		return a.ss < b.ss;
	});
	vector<int> ans;
	{
		vector<int> temp;
		for(int i = 0; i < sz(less); ++i) {
			if(i == 0) temp.push_back(ind[less[i].ff]);
			else {
				assert(less[i].ff < less[i - 1].ss);
				temp.push_back(ind[less[i].ff]);
			}
		}
		ans = temp;
	}
	{
		vector<int> temp;
		for(int i = 0; i < sz(more); ++i) {
			if(i == 0) temp.push_back(ind[more[i].ff]);
			else {
				assert(more[i].ff > more[i - 1].ss);
				temp.push_back(ind[more[i].ss]);
			}
		}
		if(sz(temp) > sz(ans)) ans = temp;
	}
	cout << sz(ans) << '\n';
	for(auto & val : ans) cout << val + 1 << ' ';
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
