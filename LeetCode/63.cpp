class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        dp[n - 1][m - 1] = ((v[n - 1][m - 1] == 0) ? 1 : 0);
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                if(i == n - 1 && j == m - 1) continue;
                else {
                    if(v[i][j] == 1) dp[i][j] = 0;
                    else {
                        if(i + 1 < n) dp[i][j] += dp[i + 1][j];
                        if(j + 1 < m) dp[i][j] += dp[i][j + 1];
                    }
                }
            }
        }
        return dp[0][0];
    }
};
