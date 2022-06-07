class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isValid(int i, int j) {
        return ((i >= 0 && j >= 0) && (i < n && j < m));
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
        // x, y, length, cleared
        queue<array<int, 4>> q;
        q.push({n - 1, m - 1, 0, 0});
        vis[n - 1][m - 1][0] = true;
        while(!q.empty()) {
            int i = q.front()[0], j = q.front()[1], len = q.front()[2], clear = q.front()[3];
            q.pop();
            if(i == 0 && j == 0) {
                return len;
            }
            for(int z = 0; z < 4; ++z) {
                int ni = i + dx[z], nj = j + dy[z];
                if(isValid(ni, nj)) {
                    if(grid[ni][nj] == 0 && !vis[ni][nj][clear]) {
                        vis[ni][nj][clear] = true;
                        q.push({ni, nj, len + 1, clear});
                    }
                    else if(grid[ni][nj] == 1 && (clear + 1 <= k) && !vis[ni][nj][clear + 1]) {
                        vis[ni][nj][clear + 1] = true;
                        q.push({ni, nj, len + 1, clear + 1});
                    }
                }
            }
        }
        return -1;
    }
};
