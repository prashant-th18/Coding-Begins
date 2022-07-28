class Solution {
public:
    int countSquares1(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dp[i + 1][j + 1] = (mat[i][j] == 1) + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int s = 1, e = min(n - i, m - j);
                int t = 0;
                while(s <= e) {
                    int mid = (s + e) / 2;
                    int ni = i + mid - 1, nj = j + mid - 1;
                    int temp = dp[ni + 1][nj + 1] - dp[ni + 1][j] - dp[i][nj + 1] + dp[i][j];
                    if(temp == mid * mid) {
                        t = mid;
                        s = mid + 1;
                    }
                    else e = mid - 1;
                }
                ans += t;
            }
        }
        return ans;
    }
    int countSquares(vector<vector<int>>& m) {
        int res = 0;
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if(m[i][j] && i && j) {
                    m[i][j] = 1 + min({m[i - 1][j], m[i - 1][j - 1], m[i][j - 1]});
                }
                res += m[i][j];
            }
        }
        return res;
    }
};
