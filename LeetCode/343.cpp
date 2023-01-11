class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for(int i = 2; i <= n; ++i) {
			for(int j = i - 1; j >= 1; --j) {
				dp[i] = max(dp[i], (i - j) * dp[j]);
			}
			if(i != n) dp[i] = max(dp[i], i);
		}
		return dp[n];
    }
};
