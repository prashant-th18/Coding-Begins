class Solution {
    public:
        int swimInWater(vector<vector<int>>& v) {
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            int n = v.size(), maxx = n * n;
            auto valid = [&](int i, int j) -> bool {
                return 0 <= i && i <= n - 1 && 0 <= j && j <= n - 1;
            };
            int mini = INT_MAX;
            int s = 0, e = maxx;
            while(s <= e) {
                int mid = (s + e) >> 1;
                vector<vector<bool>> vis(n, vector<bool>(n, false));
                queue<array<int, 2>> q;
                bool flag = false;
                if(mid >= v[0][0]) q.push({0, 0}), vis[0][0] = true;
                while(!q.empty()) {
                    array<int, 2> t = q.front(); q.pop();
                    int i = t[0], j = t[1];
                    if(i == n - 1 && j == n - 1) {
                        flag = true; break;
                    }
                    for(int k = 0; k < 4; ++k) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if(valid(ni, nj) && !vis[ni][nj]) {
                            if(v[ni][nj] <= mid) {
                                vis[ni][nj] = true; q.push({ni, nj});
                            }
                        }
                    }
                }
                if(flag) {
                    mini = mid; e = mid - 1;
                }
                else s = mid + 1;
            }
            return mini;
        }
};
