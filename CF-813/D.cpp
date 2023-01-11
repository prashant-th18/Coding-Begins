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

const ll INF = 1e9;
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = LLONG_MIN;
    for(int i = 0; i <= n - k; ++i) {
        // Inside
        ll t1 = LLONG_MIN;
        if(k != 1) {
            if(i == 0) {
                if(i == n - k) {
                    t1 = INF;
                }
                else {
                    t1 = 2 * v[i + k];
                    t1 = min(t1, INF);
                }
            }
            else {
                t1 = 2 * v[0];
                t1 = min(t1, INF);
            }
        }

        ll t2 = LLONG_MIN;
        // Outside
        if(k != n) {
            if(i != 0) {
                if(i == n - k) {
                    t2 = min(v[i - 1], 2 * v[0]);
                    t2 = min(t2, INF);
                }
                else {
                    t2 = min({INF, v[n - 1], 2 * v[0]});
                }
            }
            else {
                t2 = min({INF, 2 * v[i + k], v[n - 1]});
            }
        }
        ll t3 = LLONG_MIN;
        if(i + k <= n - 3) {
            t3 = v[n - 2];
            t3 = min(t3, 2 * v[n - 3]);
        }
        ans = max({ans, t1, t2, t3});
    }
    if(ans == LLONG_MIN) assert(false);
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
