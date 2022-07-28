class Solution {
public:
    vector<int> dp;
    int solve(int tar) {
        // dp[i] -> Minimum instructions to go from initial position "0" to final position "i", with initial speed
        // == 1
        if(dp[tar] > 0) return dp[tar];
        dp[tar] = INT_MAX;
        int j = 1, m = 1;
        // Suppose I need to earch tar
        // So, m is the number of "A" after which we will apply reverse operation "R"
        // So, j = 2 ^ m - 1
        // 3 cases:
        // 1. j < i: So, now since direction is reversed, so we need to know the number of "A" after first "R"
        // after which "R" is again used
        // 2. j == i: We have reached our target
        // 3. j > i: Now we just need to go to the back position since we have reached ahead of "i"
        for(; j < tar; j = (1 << (++m)) - 1) {
            // New position reached = "j"
            // we are less than "tar"
            for(int q = 0, p = 0; p < j; p = (1 << (++q)) - 1) {
                dp[tar] = min(dp[tar], m + (1) + q + (1) + solve(tar - (j - p)));
            }
        }
        dp[tar] = min(dp[tar], m + ((j == tar) ? (0) : (1 + solve(j - tar))));
        return dp[tar];
    }
    int racecar(int target) {
        dp.assign((1e5 + 1), -1);
        return solve(target);
    }
};
