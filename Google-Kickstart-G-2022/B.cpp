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
    ll rs, rh; cin >> rs >> rh; // Each stone radius -> rs
								// Disk radius -> rh
	int n, m;
	cin >> n;
	vector<pll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i].ff >> a[i].ss;
	cin >> m;
	vector<pll> b(m);
	for(int i = 0; i < m; ++i) cin >> b[i].ff >> b[i].ss;
	set<ll> fa, fb;
	ll rad = (rs + rh) * (rs + rh);
	for(int i = 0; i < n; ++i) {
		ll c = a[i].ff * a[i].ff + a[i].ss * a[i].ss;
		if(c <= rad) {
			fa.insert(c);
		}
	}
	for(int i = 0; i < m; ++i) {
		ll c = b[i].ff * b[i].ff + b[i].ss * b[i].ss;
		if(c <= rad) fb.insert(c);
	}
	auto f = [&](vector<pll>& v, set<ll>& st, ll& val) {
		for(int i = 0; i < sz(v); ++i) {
			ll c = v[i].ff * v[i].ff + v[i].ss * v[i].ss;
			if(c <= rad) {
				if(st.upper_bound(c) == st.begin()) {
					++val;
				}
			}
		}
	};
	ll x = 0, y = 0;
	f(a, fb, x); f(b, fa, y);
	cout << x << ' ' << y;
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
