#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "debug.h"
#else
    #include "bits/stdc++.h"
    using namespace std;
    typedef long long ll;
    #define sz(s) ((int)s.size())
    #define all(v) begin(v), end(v)
    #define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    ll n, p, k; cin >> n >> p >> k;
    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff;
        v[i].ss = i;
    }
    vector<vector<ll>> mat(n, vector<ll>(p, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> mat[i][j];
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << p, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < (1 << p); ++j) {
            dp[i][j] = dp[i - 1][j];
            for(int l = 0; l < p; ++l) {
                if(j & (1 << l)) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j ^ (1 << l)] + mat[i - 1][l]);
                }
            }
        }
    }
    set<int> st;
    int res = (1 << p) - 1;
    for(int i = n; i >= 1; --i) {
        ll maxx = dp[i - 1][res], select = -1;
        for(int j = 0; j < p; ++j) {
            if(res & (1 << j)) {
                ll t = dp[i - 1][res ^ (1 << j)] + mat[i - 1][j];
                if(t >= maxx) {
                    maxx = t;
                    select = j;
                }
            }
        }
        if(select != -1) {
            res ^= (1 << select);
            st.insert(i - 1);
        }
    }
	debug(st);
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
	ll ans = dp[n][(1 << p) - 1];
	for(int i = 0, c = 0; i < n && c < k; ++i) {
		if(!st.count(v[i].ss)) {
			ans += v[i].ff;
			++c;
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
