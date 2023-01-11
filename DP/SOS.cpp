/*
 * I will be addressing the following problem: Given a fixed array A of 2^N integers, we need to calculate 
 * ∀ x function F(x) = Sum of all A[i] such that x&i = i, i.e., i is a subset of x.
 */
#include"bits/stdc++.h"
using namespace std;
int n;
vector<int> v;
void SOSBrute() {
    vector<int> F(1 << n, 0);
    // Finds the Sum Over Subset (SOS) in brute force manner
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < (1 << n); ++i) {
            if((mask & (i)) == i) {
                // So, that means the set "i", is a subset of "mask"
                // Therefore, A[i] should be added to F[mask]
                F[mask] += v[i];
            }
        }
    }
    // This solution is quite straightforward and inefficient with time complexity of O(4^N)
}
void SOSSuboptimal() {
    vector<int> F(1 << n, 0);
    // iterate over all the masks
    for(int mask = 0; mask < (1 << n); ++mask) {
        F[mask] = v[0];
        // iterate over all the subsets of the mask
        for(int i = mask; i > 0; i = (i - 1) & mask) {
            F[mask] += v[i];
        }
    }
    // this solution is more efficient with time complexity of O(3^N)
}
void SOSFast1() {
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    vector<int> F(1 << n, 0);
    // dp[i][j] -> Suppose your mask is "i", then if you are allowed to change only the first "j" bits
    // (0-Based) of your mask, then what will be the sum of all of that submasks.
    for(int mask = 0; mask < (1 << n); ++mask) {
        dp[mask][-1] = v[mask]; // Base Case: -1 tells that you will not change any bit
                                // handle base case separately (leaf states)
        for(int i = 0; i < n; ++i) {
            dp[mask][i] = dp[mask][i - 1];
            if(mask & (1 << i)) {
                dp[mask][i] += dp[mask ^ (1 << i)][i - 1];
            }
        }
        F[mask] = dp[mask][n - 1];
    }
    // The above algorithm runs in O(N^2 * N) time.
}
//memory optimized, super easy to code.
void SOSFast2() {
    vector<int> F(1 << n, 0);
    for(int i = 0; i < (1 << n); ++i) {
        F[i] += v[i];
    }
    for(int i = 0; i < n; ++i) {
        for(int mask = 0; mask < (1 << n); ++mask) {
            if(mask & (1 << i)) {
                F[mask] += F[mask ^ (1 << i)];
            }
        }
    }
    // The above algorithm runs in O(N^2 * N) time.
}
int main() {
    cin >> n;
    v.assign(1 << n, 0);
    for (int i = 0; i < (1 << n); i++) {
        cin >> v[i];
    }
    SOSBrute();
    return 0;
}
