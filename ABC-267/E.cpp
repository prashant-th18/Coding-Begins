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
    ll n, m; cin >> n >> m;
	vector<ll> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
	}
	vector<vector<ll>> v(n + 1, vector<ll>());
	for(int i = 0; i < m; ++i) {
		ll aa, b; cin >> aa >> b;
		v[aa].push_back(b);
		v[b].push_back(aa);
	}
	vector<ll> values(n + 1, 0);
	set<pll> st;
	for(int i = 1; i <= n; ++i) {
		ll sum = 0;
		for(int j = 0; j < sz(v[i]); ++j) {
			sum += a[v[i][j]];
		}
		st.insert(pll(sum, i));
		values[i] = sum;
	}
	ll ans = LLONG_MIN;
	vector<bool> exist(n + 1, true);
	while(!st.empty()) {
		pll f = *st.begin();
		st.erase(st.begin());
		ans = max(ans, f.ff);
		int node = f.ss;
		exist[node] = false;
		for(auto& val : v[node]) {
			if(!exist[val]) continue;
			ll pre = values[val];
			auto it = st.find(pll(pre, val));
			assert(it != st.end());
			st.erase(it);
			values[val] -= a[node];
			st.insert(pll(values[val], val));
		}
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
