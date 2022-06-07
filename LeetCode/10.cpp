class Solution {
public:
    bool isMatch(string s, string p) {
        string q = "";
        vector<bool> check;
        for(int i = 0; i < p.size(); ++i) {
            if(p[i] != '*') {
                q += p[i];
                check.emplace_back(false);
            }
            else check[check.size() - 1] = true;
        }
        // work with s and q
        int n = s.size(), m = q.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        for(int i = n; i >= 0; --i) {
            for(int j = m; j >= 0; --j) {
                if(i == n && j == m) dp[i][j] = true;
                else if(j == m) {
                    dp[i][j] = false;
                }
                else if(i == n) {
                    bool flag = true;
                    for(int k = j; k < m; ++k) {
                        flag &= check[k];
                    }
                    dp[i][j] = flag;
                }
                else {
                    if(check[j]) {
                        // 0, 1, 2, 3, times
                        dp[i][j] = dp[i][j + 1];
                        for(int k = i + 1; k <= n; ++k) {
                            if(s[k - 1] == q[j] || q[j] == '.') {
                                dp[i][j] = dp[i][j] | (dp[k][j + 1]);
                            }
                            else break;
                        }
                    }
                    else {
                        if(q[j] == '.' || s[i] == q[j]) dp[i][j] = dp[i + 1][j + 1];
                    }
                }
            }
        }
        return dp[0][0];
    }
};
