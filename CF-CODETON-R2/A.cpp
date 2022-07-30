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
    string a, b; cin >> a >> b;
    string ch = b.substr(1);
    string ch2 = a.substr(n - sz(ch));
    if(ch != ch2) cout << "NO";
    else {
        char c1 = b[0];
        char c2 = a[n - m];
        if(c1 == c2) cout << "YEs";
        else {
            if(c2 == '0') {
                for(int i = n - m - 1; i >= 0; --i) {
                    if(a[i] == '1') {
                        cout << "Yes";
                        return 0;
                    }
                }
                cout << "NO";
                return 0;
            }
            else {
                for(int i = n - m - 1; i >= 0; --i) {
                    if(a[i] == '0') {
                        cout << "YES"; return 0;
                    }
                }
                cout << "NO";
            }
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
