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
	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);
	ll n; cin >> n; // Number of cows
	vector<vector<ll>> v(n, vector<ll>(5, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 5; ++j) cin >> v[i][j];
		sort(all(v[i]));
	}
	/* Why sorting? Didn't get it!
	*/
	sort(all(v), [&](const vector<ll>& a, const vector<ll>& b) {
			for(int j = 0; j < 5; ++j) {
				if(a[j] < b[j]) return true;
				if(a[j] > b[j]) return false;
			}
			return false;
			});
	map<vector<int>, ll> mp;
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j < (1 << 5); ++j) {
			vector<int> t;
			for(int k = 0; k < 5; ++k) if(j & (1 << k)) t.push_back(v[i][k]);
			mp[t]++;
		}
	}
	ll ans = n * (n - 1) / 2;
	for(auto& p : mp) {
		auto& t = p.ff;
		auto& val = p.ss;
		if(sz(t) & 1) {
			ans -= val * (val - 1) / 2;
		}
		else ans += val * (val - 1) / 2;
	}
	cout << ans;
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
