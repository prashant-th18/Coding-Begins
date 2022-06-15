class Solution {
public:
    int checkRecord(int n) {
        long long MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 10, vector<vector<long long>>(3, vector<long long>(2, 0)));
        dp[n - 1][0][0] = dp[n - 1][1][0] = dp[n - 1][2][0] = 1;
        // 0 -> Absent
        // 1 -> Late
        // 2 -> Present
        
        for(int i = n - 2; i >= 0; --i) {
            dp[i][2][0] = (dp[i + 1][1][0] + dp[i + 1][2][0]) % MOD;

            dp[i][2][1] = ((dp[i + 1][0][0] + dp[i + 1][1][1]) % MOD + dp[i + 1][2][1]) % MOD;

            dp[i][1][0] = ((((dp[i + 1][2][0] + dp[i + 1][1][0]) % MOD - dp[i + 2][1][0]) + MOD) % MOD);

            dp[i][1][1] = ((((dp[i + 1][2][1] + dp[i + 1][0][0]) % MOD + dp[i + 1][1][1]) % MOD - dp[i + 2][1][1]) + MOD) % MOD;

            dp[i][0][0] = (dp[i + 1][1][0] + dp[i + 1][2][0]) % MOD;
        }
        long long sum = 0;
        for(int i = 0; i < 3; ++i) {
            sum = (sum + (dp[0][i][0] + dp[0][i][1]) % MOD) % MOD;
        }
        return sum;
    }
};

