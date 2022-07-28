class DetectSquares {
    public:
        vector<vector<int>> v;
        vector<vector<int>> pos;
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        bool isValid(int i, int j) {
            return ((i >= 0 && j >= 0 && i <= 1000 && j <= 1000));
        }
        DetectSquares() {
            v.assign(1001, vector<int>(1001, 0));
            pos.assign(1001, vector<int>());
        }

        void add(vector<int> p) {
            v[p[0]][p[1]]++;
            pos[p[0]].push_back(p[1]);
        }

        int count(vector<int> p) {
            int ans = 0;
            int x = p[0], y = p[1];
            for(int i = 0; i < pos[x].size(); ++i) {
                if(pos[x][i] == y) continue;
                else {
                    int dis = abs(y - pos[x][i]);
                    int nx = x, ny = y - dis;
                    int xn = x, yn = y + dis;
                    if(isValid(nx, ny)) {
                        // nx, pos[x][i]
                        ans += (1 * v[nx][ny] * v[pos[x][i]][ny]);
                    }
                    if(isValid(xn, yn)) {
                        ans += (1 * v[xn][yn] * v[pos[x][i]][yn]);
                    }
                }
            }
            return ans;
        }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
