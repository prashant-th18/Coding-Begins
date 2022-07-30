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

const int maxx = 50;
// *-> KISS*
int solve() {
    int n, even = 0, odd = 0; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == 0) continue;
    }
    odd = (n + 1) / 2;
    even = n / 2;
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(maxx + 1, vector<vector<int>>(maxx + 1, vector<int>(2, 1e6))));
    // dp[i][j][k][l] -> till index "i", if I have "j" odd and "k" even numbers, what is the minimum 
    // complexity I can get, if parity of number at index "i" is "l"(1 for odd, 0 for even).
    // Base Case
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= maxx; ++j) {
            for(int k = 0; k <= maxx; ++k) {
                // Place Odd here :
                // "i - 1" -> even 
                // "i - 1" -> odd
                //
                // Place Even here :
                // "i - 1" -> odd
                // "i - 1" -> even

                // Check if a number exist on index "i" or not
                [[likely]] if(v[i - 1] == 0) {
                    // Let's place even here
                    if(k != 0) {
                        dp[i][j][k][0] = min(dp[i - 1][j][k - 1][0], 1 + dp[i - 1][j][k - 1][1]);
                    }
                    if(j != 0) {
                        dp[i][j][k][1] = min(dp[i - 1][j - 1][k][1], 1 + dp[i - 1][j - 1][k][0]);
                    }
                }
                else {
                    int f = (v[i - 1] & 1);
                    if(f) {
                        if(j != 0) {
                            dp[i][j][k][f] = min(dp[i - 1][j - 1][k][f], 1 + dp[i - 1][j - 1][k][1 ^ f]);
                        }
                    }
                    else {
                        // Number at index "i" is even
                        if(k != 0) {
                            dp[i][j][k][f] = min(dp[i - 1][j][k - 1][f], 1 + dp[i - 1][j][k - 1][1 ^ f]);
                        }
                    }
                }
            }
        }
    }
    cout << min(dp[n][odd][even][0], dp[n][odd][even][1]);
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
