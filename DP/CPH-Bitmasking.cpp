/*
 * We are given the prices of k products over n days, and we want to buy each product exactly once. 
 * However, we are allowed to buy at most one product in a day. What is the minimum total price?
 */
#include"bits/stdc++.h"
using namespace std;
using ll = long long;
const int K = 3, N = 8;
ll dp[1 << K][N], price[K][N];
// Dp state is -> dp[i][j] -> Minimum price to buy the subset "i" in "j" days
int main() {
    memset(price, 0, sizeof(price));
    for(int i = 0; i < (1 << K); ++i) {
        for(int j = 0; j < N; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < N; ++j) cin >> price[i][j];
    }
    // price[i][j] -> price of "ith" product on day "j"
    for(int i = 0; i < K; ++i) {
        dp[1 << i][0] = price[i][0];
    }
    for(int x = 1; x < N; ++x) { // x -> denotes current day
        for(int s = 0; s < (1 << K); ++s) { // s- > subset of persons
            dp[s][x] = dp[s][x - 1];
            for(int i = 0; i < K; ++i) {
                if(s & (1 << i)) {
                    dp[s][x] = min(dp[s][x], price[i][x] + dp[s ^ (1 << i)][x - 1]);
                }
            }
        }
    }
    cout << dp[(1 << K) - 1][N - 1];
    return 0;
}
