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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), pos(n + 1), c(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = pos[b[i]];
    }
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto up = upper_bound(all(lis), c[i]) - begin(lis);
        if(up == sz(lis)) {
            lis.push_back(c[i]);
        }
        else {
            lis[up] = c[i];
        }
    }
    cout << sz(lis);
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
