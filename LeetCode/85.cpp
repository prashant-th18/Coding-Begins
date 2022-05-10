class Solution {
public:
    int maximalRectangle(vector<vector<char>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 0));
        for(int j = 0; j < m; ++j) {
            for(int i = n - 1; i >= 0; --i) {
                if(i == n - 1) pre[i][j] = v[i][j] - '0';
                else {
                    pre[i][j] = ((v[i][j] == '0') ? (0) : (1 + pre[i + 1][j]));
                }
            }
        }
        int area = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int mini = pre[i][j];
                int ind = j + 1;
                while(ind < m && mini != 0) {
                    area = max(area, mini * (ind - j));
                    mini = min(mini, pre[i][ind]);
                    ++ind;
                }
                area = max(area, mini * (ind - j));
            }
        }
        return area;
    }
};
