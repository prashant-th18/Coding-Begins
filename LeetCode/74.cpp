class Solution {
public:
    bool findIt(vector<vector<int>>& matrix, int ans, int target) {
        if(ans == -1) return false;
        int s = 0, e = matrix[ans].size() - 1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            if(matrix[ans][mid] < target) {
                s = mid + 1;
            }
            else if(matrix[ans][mid] > target) {
                e = mid - 1;
            }
            else return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = -1;
        int s = 0, e = m - 1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            int l = matrix[mid][0], r = matrix[mid][n - 1];
            if(target < l) e = mid - 1;
            else if(target > r) s = mid + 1;
            else {
                ans = mid; break;
            }
        }
        return findIt(matrix, ans, target);
    }
};
