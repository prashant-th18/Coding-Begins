class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int c = 0;
        int m = v.size(), n = v[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                c += (v[i][j] == 1);
            }
        }
        queue<array<int, 3>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                array<int, 3> temp = {i, j, 0};
                if(v[i][j] == 2) q.push(temp), vis[i][j] = true;
                else if(v[i][j] == 0) vis[i][j] = true;
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        auto valid = [&](int i, int j) {
            return (i >= 0 && i < m && j >= 0 && j < n && !vis[i][j]);
        };
        while(!q.empty()) {
            array<int, 3> temp = q.front(); q.pop();
            for(int k = 0; k < 4; ++k) {
                int ni = temp[0] + dx[k], nj = temp[1] + dy[k];
                if(valid(ni, nj)) {
                    vis[ni][nj] = true;
                    --c;
                    q.push({ni, nj, temp[2] + 1});
                    if(c == 0) return temp[2] + 1;
                }
            }
        }
        if(c != 0) return -1;
        return 0;
    }
};
