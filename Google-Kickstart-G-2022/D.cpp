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

// *-> KISS*
int solve() {
	int n; cin >> n;
	ll e; cin >> e;
	vector<pll> v(n);
	vector<ll> c(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i].ff >> v[i].ss;
		cin >> c[i];
	}
	vector<int> ind(n);
	iota(all(ind), 0);
	ll maxx = 0;
	do {
		ll ans = 0;
		ll x = 0, y = (ll)1e18, dir = 1;
		for(int j = 0; j < n; ++j) {
			int i = ind[j];
			if(v[i].ss > y) continue;
			else {
				if(dir == 1) {
					if(x <= v[i].ff) {
						x = v[i].ff;
						y = v[i].ss;
						ans += c[i];
					}
					else {
						dir = 0;
						x = v[i].ff; y = v[i].ss;
						ans += c[i]; ans -= e;
					}
				}
				else {
					if(v[i].ff <= x) {
						x = v[i].ff;
						ans += c[i]; y = v[i].ss;
					}
					else {
						dir = 1; x = v[i].ff; y = v[i].ss; ans -= e; ans += c[i];
					}
				}
			}
			maxx = max(maxx, ans);
		}
	} while (next_permutation(all(ind)));
	cout << maxx;
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
		cout << "Case #" << i << ": ";
			if (solve()) {
            break;
        }
        cout << '\n';
    }
	return 0;
}
// -> Keep It Simple Stupid!
