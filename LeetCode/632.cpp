class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); ++j) ans.push_back({nums[i][j], i});
        }
        sort(ans.begin(), ans.end());
        vector<int> cnt(nums.size(), 0);
        int i = 0, j = 0, all = 0;
        while(all < nums.size()) {
            ++cnt[ans[j].second];
            if(cnt[ans[j].second] == 1) ++all;
            ++j;
        }
        --j;
        int mini = INT_MAX;
        mini = ans[j].first - ans[i].first;
        int x = ans[i].first, y = ans[j].first;
        --cnt[ans[j].second];
        while(j < ans.size()) {
            cnt[ans[j].second]++;
            while(cnt[ans[i].second] > 1) {
                --cnt[ans[i].second];
                ++i;
            }
            int num = ans[j].first - ans[i].first;
            if(num < mini) {
                mini = num;
                x = ans[i].first, y = ans[j].first;
            }
            ++j;
        }
        vector<int> a; a.push_back(x); a.push_back(y);
        return a;
    }
};
