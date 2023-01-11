#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "debug.h"
#else 
    #define debug(...)
#endif

#ifndef LOCAL
    #include "bits/stdc++.h"
    using namespace std;
    typedef long long ll;
    #define sz(s) ((int)s.size())
    #define all(v) begin(v), end(v)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    ll n, m, k; cin >> n >> m >> k;
    std::vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> dp(n, 0);
    for(int i = 0; i < n; ++i) {
        ll s = -k;
        int j = i, cnt = 0;
        while(cnt < m - 1 && j >= 0) {
            s += v[j--];
            ++cnt;
            dp[i] = max(dp[i], s);
        }
        if(j >= 0) {
            s += v[j--];
            dp[i] = max(dp[i], s);
            if(j >= 0) {
                dp[i] = max(dp[i], s + dp[j]);
            }
        }
    }
    cout << *max_element(all(dp));
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
