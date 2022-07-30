#define sz(x) (int)(x.size())
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> in(n, 0);
        int op = -1;
        for(int i = 1; i <= n * n - k + 1; ++i) {
            int ind = -1, mini = INT_MIN;
            for(int j = 0; j < n; ++j) {
                if(sz(mat[j]) == 0) continue;
                else {
                    if(mat[j].back() > mini) {
                        mini = mat[j].back();
                        ind = j;
                    }
                }
            }
            mat[ind].pop_back();
            if(i == n * n - k + 1) {
                op = mini;
            }
        }
        return op;
    }
};
