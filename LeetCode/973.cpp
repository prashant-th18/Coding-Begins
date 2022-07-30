class Solution {
public:
    vector<vector<int>> kClosestSlow(vector<vector<int>>& v, int k) {
        int n = v.size();
        sort(v.begin(), v.end(), [&](vector<int>& a, vector<int>& b) {
            int d1 = a[0] * a[0] + a[1] * a[1], d2 = b[0] * b[0] + b[1] * b[1];
            return d1 < d2;
        });
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i]);
        }
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        int n = v.size();
        // Partial_sort sorts first k elements
        partial_sort(v.begin(), v.begin() + k, v.end(), [&](vector<int>& a, vector<int>& b) {
            int d1 = a[0] * a[0] + a[1] * a[1], d2 = b[0] * b[0] + b[1] * b[1];
            return d1 < d2;
        });
        return vector<vector<int>>(v.begin(), v.begin() + k);
    }
};
