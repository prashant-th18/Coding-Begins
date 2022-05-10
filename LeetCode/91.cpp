class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // Base Case
        dp[n - 1] = (s[n - 1] != '0');
        dp[n] = 1;
        for(int i = n - 2; i >= 0; --i) {
            if(s[i] == '0') dp[i] = 0;
            else {
                int op1 = dp[i + 1];
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                int op2 = 0;
                if(num <= 26) {
                    op2 += dp[i + 2];
                }
                dp[i] = (op1 + op2);
            }
        }
        return dp[0];
    }
};
