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
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> ans;
    int win = -1;
    if(v[0] > v[1]) win = 0;
    else win = 1;
    ans.push_back(win);
    for(int i = 2; i < n; ++i) {
        if(v[i] > v[win]) {
            win = i;
        }
        ans.push_back(win);
    }
    while(sz(ans) >= 2) {
        if(ans[sz(ans) - 1] == ans[sz(ans) - 2]) ans.pop_back();
        else break;
    }
    debug(ans);
    vector<vector<int>> temp(n + 1);
    for(int i = 0; i < sz(ans); ++i) {
        temp[ans[i] + 1].push_back(i + 1);
    }
    while(q--) {
        int in, k; cin >> in >> k;
        if(sz(temp[in]) == 0) cout << 0 << '\n';
        else {
            auto& a = temp[in];
            int extra = 0;
            if(ans.back() + 1 == in && a[sz(a) - 1] < k) {
                extra += k - a[sz(a) - 1];
                k = a[sz(a) - 1];
            }
            extra += (upper_bound(all(a), k) - begin(a));
            cout << extra << '\n';
        }
    }
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
