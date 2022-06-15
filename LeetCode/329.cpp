class Solution {
public:
    vector<vector<int>> v;
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool valid(int i, int j) {
        if(0 <= i && i < n && 0 <= j && j < m) return true;
        return false;
    }
    vector<vector<int>> dp;
    int dfs(int i, int j) {
        int c = 0;
        for(int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if(valid(ni, nj) && v[ni][nj] > v[i][j]) {
                if(dp[ni][nj] != 0) c = max(c, dp[ni][nj]);
                else c = max(c, dfs(ni, nj));
            }
        }
        c += 1;
        return dp[i][j] = c;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        v = matrix;
        n = matrix.size(), m = matrix[0].size();
        dp.assign(n, vector<int>(m, 0));
        int maxx = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dp[i][j] == 0) dfs(i, j);
                maxx = max(maxx, dp[i][j]);
            }
        }
        return maxx;
    }
};
