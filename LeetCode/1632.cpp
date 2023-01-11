class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        set<array<int, 3>> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                st.insert({v[i][j], i, j});
            }
        }
        while(!st.empty()) {
            
        }
    }
};
