#define ff first
#define ss second
class Solution {
    public:
        bool zero(vector<vector<int>>& t) {
            for(int i = 0; i < t.size(); ++i) {
                for(int j = 0; j < t[0].size(); ++j) {
                    if(t[i][j] == 1) return false;
                }
            }
            return true;
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        void flip(int i, int j, vector<vector<int>>& t) {   
            int n = t.size(), m = t[0].size();
            t[i][j] = 1 - t[i][j];
            for(int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    t[ni][nj] = 1 - t[ni][nj];
                }
            }
        }
        void unflip(int i, int j, vector<vector<int>>& t) {
            int n = t.size(), m = t[0].size();
            t[i][j] = 1 - t[i][j];
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    t[ni][nj] = 1 - t[ni][nj];
                }
            }
        }
        int minFlips(vector<vector<int>>& mat) {
            set<vector<vector<int>>> st;
            st.insert(mat);
            queue<pair<vector<vector<int>>, int>> q;
            q.push(pair(mat, 0));

            int n = mat.size(), m = mat[0].size();
            while(!q.empty()) {
                vector<vector<int>> t = q.front().ff;
                int c = q.front().ss;
                q.pop();
                if(zero(t)) {
                    return c;
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        // Flip [i][j]
                        flip(i, j, t);
                        if(!st.count(t)) {
                            q.push(pair(t, c + 1));
                            st.insert(t);
                        }
                        unflip(i, j, t);
                    }
                }
            }
            return -1;
        }
};
