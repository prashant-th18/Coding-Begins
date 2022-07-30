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
    int n, m; cin >> n >> m;
    vector<int> v(n, -1);
    vector<array<int, 3>> arr(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    vector<int> b(n, -1);
    for (int i = 0; i < m; i++) {
        if(arr[i][0] == 1) {
            for(int j = arr[i][1] - 1; j < arr[i][2] - 1; ++j) {
                b[j] = 0;
            }
        }
    }
    v[0] = n;
    for(int i = 1; i < n; ++i) {
        v[i] = v[i - 1] + b[i - 1];
    }
    for(int i = 0; i < m; ++i) {
        if(arr[i][0] == 0) {
            int l = arr[i][1] - 1;
            int r = arr[i][2] - 1;
            if(is_sorted(v.begin() + l, v.begin() + r + 1)) {
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES\n";
    for(auto val : v) cout << val << ' ';
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
