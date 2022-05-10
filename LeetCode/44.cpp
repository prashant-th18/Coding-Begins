class Solution {
public:
    bool isMatch(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        vector<vector<bool>> pos(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for(int i = n; i >= 0; --i) {
            for(int j = m; j >= 0; --j) {
                if(i == n && j == m) dp[i][j] = true;
                else if(j == m) {
                    dp[i][j] = false;
                }
                else if(i == n) {
                    if(('a' <= b[j] && b[j] <= 'z') || (b[j] == '?')) dp[i][j] = false;
                    else {
                        dp[i][j] = dp[i][j + 1];
                    }
                }
                else {
                    if('a' <= b[j] && b[j] <= 'z') {
                        if(a[i] != b[j]) dp[i][j] = false;
                        else {
                            dp[i][j] = dp[i + 1][j + 1];
                        }
                    }
                    else {
                        if(b[j] == '?') dp[i][j] = dp[i + 1][j + 1];
                        else {
                            dp[i][j] = pos[i][j + 1];
                        }
                    }
                }
                if(i != n) pos[i][j] = pos[i + 1][j] | dp[i][j];
                else pos[i][j] = dp[i][j];
            }
        }
        return dp[0][0];
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
