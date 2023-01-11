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
vector<pll> g;
ll fun(ll in, ll num) {
	ll how = 0;
	for(int i = 0; i < sz(g); ++i) {
		ll h = g[i].ff, inn = g[i].ss;
		if(inn == in) continue;
		if(num >= h) {
			++how;
			num -= h;
		}
	}
	return how;
}
// *-> KISS*
int solve() {
	g.clear();
    ll n, m; cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
   
    for(int i = 0; i < n; ++i) {
    	g.push_back({v[i], i});
    }
    
    sort(all(g));
    
    ll s = 1, e = n;
	ll ans = n + 1;
	while(s <= e) {
		ll mid = (s + e) >> 1;
		// Okay I want to achieve position mid
		
		ll maxx = n - mid;
		ll t = m;
		bool ok = false;
		// Okay Kill this
		if(v[maxx] <= t) {
			ll my = 1 + fun(maxx, t - v[maxx]);
			ok |= (my >= maxx);
		}
		if(!ok) ok |= (fun(-1, t) >= (maxx + 1));
		
		if(ok) {
			ans = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
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