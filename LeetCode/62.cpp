class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(j + 1 < n) dp[i][j] += dp[i][j + 1];
                if(i + 1 < m) dp[i][j] += dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};
