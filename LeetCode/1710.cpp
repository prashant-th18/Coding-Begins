class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int s) {
        int n = v.size();
       sort(v.begin(), v.end(), [&](vector<int>& a, vector<int>& b) {
           return a[1] > b[1];
       });
       int ans = 0;
       for(int i = 0; i < n && s; ++i) {
           int b = min(v[i][0], s);
           s -= b;
           ans += b * v[i][1];
       }
       return ans;
    }
};
