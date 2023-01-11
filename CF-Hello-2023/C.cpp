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

using pll = pair<ll, ll>;
int op(vector<ll> v, int m) {
	int ans = 0;
	int n = sz(v);
	ll sum = 0;
	ll till = 0;
	vector<pll> ok;
	
	for(int i = 0; i < n; ++i) {
		sum += v[i];
		if(i == m - 1) {
			till = sum;
		}
		else if(i > m - 1) {
			if(sum < till) {
				sum -= (v[i]);
				sum += (-v[i]);
				++ans;
			}
			assert(sum >= till);
		}
	}
	cout << ans << endl;
	sum = 0;
	for(int i = 0; i < m; ++i) {
		sum += v[i];
		if(sum < till) ok.push_back({i, sum});
	}
	sort(all(ok));
	ll ex = 0;
	vector<int> pre(m + 1);
	for(int i = 0; i < sz(ok); ++i) {
		ll num = ok[i].ss;
		int in = ok[i].ff;
		// cout << in << ' ' << num << endl;
		num += ex;
		if(num >= till) {}// OK
		else {
			ex += 2 * (-v[in]);
			num += (2 * (-v[in]));
			pre[i + 1] = 1;
			// ++ans;
			till += (2 * (-v[in]));
		}
	}
	return ans;
}
// *-> KISS*
int solve() {
	ll n, m; cin >> n >> m;
	vector<ll> v(n);
	vector<pll> ok;
	for(int i = 0; i < n; ++i) cin >> v[i];

	int ans = op(v, m);
	v[m - 1] = -1 * v[m - 1];
	ans = min(ans, 1 + op(v, m));
	cout << ans;
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