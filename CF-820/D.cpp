#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((ll)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    ll n; cin >> n;
	vector<ll> x(n), y(n);
	for(int i = 0; i < n; ++i) cin >> x[i];
	for(int i = 0; i < n; ++i) cin >> y[i];
	vector<ll> pos, neg;
	for(int i = 0; i < n; ++i) {
		ll t = y[i] - x[i];
		if(t >= 0) pos.push_back(t);
		else neg.push_back(t);
	}
	sort(all(pos), greater<ll>());
	sort(all(neg));
	ll maxx = 0, cnt = 0;
	for(int i = 0, j = 0; i < sz(pos); ++i) {
		if(j == sz(neg)) {
			maxx = max(maxx, cnt + (sz(pos) - i) / 2);
			break;
		}
		else {
			if(pos[i] + neg[j] >= 0) {
				++cnt;

			}
		}
	}
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
