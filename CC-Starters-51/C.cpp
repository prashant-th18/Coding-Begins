#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n;
    cin >> n;
    ll x; cin >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    array<ll, 2> temp = {0, 0};
    vector<array<ll, 2>> dp(n, temp);
    for(int i = 1; i < n; ++i) {
        dp[i][0] = max((v[i] ^ (v[i - 1])) + dp[i - 1][0], (v[i] ^ (v[i - 1] + x)) + dp[i - 1][1]);
        dp[i][1] = max(((v[i] + x) ^ (v[i - 1])) + dp[i - 1][0], ((v[i] + x) ^ (v[i - 1] + x)) + dp[i - 1][1]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
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
