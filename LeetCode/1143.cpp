class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                if(t1[i] == t2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                dp[i][j] = max({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
            }
        }
        return dp[0][0];
    }
};
