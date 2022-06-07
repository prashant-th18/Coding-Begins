class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxx = 0, start = -1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(i == j) dp[i][j] = true;
                else if(i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]);
                }
                if(dp[i][j]) {
                    if(j - i + 1 > maxx) {
                        maxx = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return (s.substr(start, maxx));
    }
};
