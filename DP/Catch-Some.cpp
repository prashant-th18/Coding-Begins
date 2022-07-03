// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2/0000000000150a0d

// Observations:
// 1. Never repeat same T-Shirt.
// 2. Except last trip, all trips are round trips.
// 3. If I am wearing a T-Shirt of color (Ci) and suppose in the optimal case, we will select a dog with color (Ci) at some position (R) and then not selecting any dog of color (Ci) ahead of this R, then we will only go till 
// position R
// In simple words, point 3 says that, maanle optimal scenario mai kisi position R jha pr dog color (Ci) ke saath 
// present hai, vha tk jaa rha hun T-Shirt Color(Ci) pehen kr, toh fir is T-Shirt ko aage pehen krr jaana useless
// hai kyuki aage is T-Shirt ke through koi aur dog select ni hora hai!
//

// We are given in the question that, colors are atmost 1000
// Therefore,
//
// DP States:
//
// dp(i, x, 0) : Minimum time to observe 'x' dogs using colors [Ci, ... C1000] given that once of them can be the
// last trip.
//
// dp(i, x, 1) : Minimum time to observe 'x' dogs using colors [Ci, ... C1000] given that all of them are round 
// trips.
//
// Answer -> dp(1, K, 0)
//
// Transitions:
//
// p[i][j] -> position of the j_th occurrence of color 'i'
//
// dp(i, x, 1): for all valid 'j': minimum of     2 * p[i][j] + dp(i + 1, x - j, 1)
//
// dp(i, x, 0): 1. Current color is round trip color
//              => 2 * p[i][j] + dp(i + 1, x - j, 0)
//              2. Current color is 1-way trip
//              => p[i][j] + dp(i + 1, x - j, 1)
//
#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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

int n, k;
vector<int> dogs;
vector<int> col;
vector<vector<int>> p;
vector<vector<vector<int>>> dp;
int solve(int in, int x, bool round) {
    // in -> index
    // x -> how many left to observe
    // round -> 1 => all of them are round
    //          0 => one of them is single trip

    if(x <= 0) return 0;
    if(in == 1001) return 1e9;

    if(dp[in][x][round] != -1) return dp[in][x][round];

    int ans = solve(in + 1, x, round); // Not choosing the "ith" color
    for(int i = 0; i < sz(p[in]); ++i) {
        if(!round) {
            ans = min(ans, p[in][i] + solve(in + 1, x - (i + 1), 1));
        }
        ans = min(ans, 2 * p[in][i] + solve(in + 1, x - (i + 1), round));
    }
    return dp[in][x][round] = ans;
}
// *-> KISS*
int solve() {
    cin >> n >> k;
    dogs.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> dogs[i];
    }
    col.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> col[i];
    }
    p.assign(1001, vector<int>());
    for (int i = 0; i < n; i++) {
        p[col[i]].push_back(dogs[i]);
    }
    for (int i = 0; i < 1001; i++) {
        sort(p[i].begin(), p[i].end());
    }
    dp.assign(1001, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    cout << solve(1, k, 0);
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
        cout << "Case #" << i << ": ";
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
