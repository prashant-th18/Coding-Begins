#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> bits(31);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            for(int j = 0; j < 31; ++j) {
                if((v[i] >> j) & 1) {
                    bits[j].push_back(i);
                }
            }
            dp[i] = 0;
        }
        else {
            bool f = false;
            vector<int> temp(31, 0);
            for (int j = 0; j < 31; j++) {
                if((v[i] >> j) & 1) {
                    temp[j] = 1;
                }
            }
            for(int j = 0; j < 31; ++j) {
                if(temp[j] && sz(bits[j])) {
                    f = true;
                    break;
                }
            }
            if(f) {
                for (int j = 0; j < 31; j++) {
                    if(temp[j]) {
                        bits[j].push_back(i);
                    }
                }
                dp[i] = dp[i - 1];
                continue;
            }
            ll ans = LLONG_MAX;
            int ind = -1; int ch = 1;
            for(int j = 0; j < 31; ++j) {
                if(sz(bits[j]) > 0) {
                    ans = (1LL << j);
                    ch = 1;
                    ind = j;
                    break
                }
                else if(temp[j]) {
                    ans = (1LL << j);
                    ind = j; ch = 2;
                    break;
                }
            }
            for(int j = 0; j < 31; ++j) {
                if(temp[j]) {
                    int in = -1;
                    for(int k = j - 1; k >= 0 && in == -1; --k) {
                        if(sz(bits[k])) in = k;
                    }
                    if(in != -1) {
                        ll maybe = (1LL << j) - (1LL << k);
                        if(ans > maybe) {
                            ans = maybe;
                            ind = in; ch = 3;
                        }
                    }
                }
                else if(sz(bits[j])) {
                    int in = -1;
                    for(int k = j - 1; k >= 0 && in == -1; --k) {
                        if(temp[k]) {
                            in = k;
                        }
                    }
                    if(in != -1) {
                        ll maybe = 
                    }
                }
            }
        }
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
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
