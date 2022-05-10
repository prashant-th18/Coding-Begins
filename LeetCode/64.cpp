class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                if(i == n - 1 && j == m - 1) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    int r = (j + 1 < m) ? (dp[i][j + 1]) : (INT_MAX);
                    int d = (i + 1 < n) ? (dp[i + 1][j]) : (INT_MAX);
                    dp[i][j] = grid[i][j] + min(r, d);
                }
            }
        }
        return dp[0][0];
    }
};
