class Solution {
    public:
        int n, m;
        bool valid(int i, int j) {
            if(i >= 0 && j >= 0 && i < n && j < m) return true;
            return false;
        }
        int longestIncreasingPath(vector<vector<int>>& v) {
            n = v.size(), m = v[0].size();
            vector<vector<int>> in(n, vector<int>(m, 0));
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(valid(ni, nj) && v[i][j] < v[ni]nj]) {
                            in[ni][nj]++;
                        }
                    }
                }
            }
            queue<array<int, 3>> q;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(in[i][j] == 0) {
                        q.push({i, j, 1});
                    }
                }
            }
            int maxx = 0;
            while(!q.empty()) {
                int i = q.front()[0], j = q.front()[1], c = q.front()[2];
                q.pop();
                maxx = max(maxx, c);
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if(valid(ni, nj) && v[i][j] < v[ni][nj]) {
                        in[ni][nj]--;
                        if(in[ni][nj] == 0) {
                            q.push({ni, nj, c + 1});
                        }
                    }
                }
            }
            return maxx;
        }
};
