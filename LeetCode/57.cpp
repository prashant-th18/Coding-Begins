class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.insert(intervals.begin(), newInterval);
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        });
        vector<vector<int>> ans;
        int minn = intervals[0][0], maxx = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(maxx < intervals[i][0]) {
                ans.push_back({minn, maxx});
                minn = intervals[i][0], maxx = intervals[i][1];
            }
            else {
                maxx = max(maxx, intervals[i][1]);
            }
        }
        ans.push_back({minn, maxx});
        return ans;
    }
};
