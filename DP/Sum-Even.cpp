/*
Coding interview problem

Find the number of lists that exist and satisfy the following:
    1.  list contains exactly 'N' elements
    2.  all elements of the list are between 'low' and 'high'
    3.  sum of all elements is even

Return answer modulo 10^9+7

Constraints
1 <= n <= 10^6
1 <= low <= high <= 10^6

Sample
(n=3,low=1,high=2) -> 4
(n=2,low=1,high=10) -> 50
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; // Number of elements
    int low, high; cin >> low >> high; // Lower and Upper Bound of numbers to be placed
    int even = (high - low + 1) / 2, low = even;
    // Calculating the number of odd and even numbers in the range [low, high]
    if(low % 2 == 0 && high % 2 == 0) ++even;
    else if(low % 2 == 1 && high % 2 == 1) ++odd;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[i][0] -> Number of Arrays from index "i" to index "n - 1", given that their sum is even
    // dp[i][1] -> Number of Arrays from index "i" to index "n - 1", given that their sum is odd
    for(int i = n - 1; i >= 0; --i) {
        if(i == n - 1) {
            // Base Cases
            dp[i][0] = even;
            dp[i][1] = odd;
        }
        else {
            // Even -> Even + Even
            //         Odd + Odd
            dp[i][0] = ((even * dp[i + 1][0] % MOD) + (odd * dp[i + 1][1]) % MOD) % MOD;
            // Odd -> Even + Odd
            //        Odd + Even
            dp[i][1] = ((even * dp[i + 1][1]) % MOD + (odd * dp[i + 1][0]) % MOD) % MOD;
        }
    }
    cout << dp[0][0];
    return 0;
}
