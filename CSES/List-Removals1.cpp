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
    int n; cin >> n;
    vector<int> v(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<int> bit(n + 1, 0);
    auto update = [&](int in, int delta = 1) -> void {
        for(; in <= n; in += (in & -in)) {
            bit[in] += delta;
        }
    };
    auto sum = [&](int in) -> int {
        int s = 0;
        for(; in > 0; in -= (in & -in)) {
            s += bit[in];
        }
        return s;
    };
    for (int i = 0; i < n; i++) {
        int index = -1;
        int s = 0, e = n - 1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            int ni = mid + 1 - sum(mid + 1);
            if(ni < t[i]) {
                s = mid + 1;
            }
            else if(ni > t[i]) e = mid - 1;
            else {
                index = mid + 1;
                e = mid - 1;
            }
        }
        assert(index != -1);
        cout << v[index - 1] << '\n';
        update(index, 1);
    }
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

