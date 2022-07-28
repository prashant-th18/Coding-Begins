class Solution {
public:
    int minDifference(vector<int>& nums) {
        // 0 1 5 10 14
        sort(nums.begin(), nums.end());
        if(nums.size() <= 4) return 0;
        int n = nums.size();
        return min({nums[n - 4] - nums[0], nums[n - 3] - nums[1], nums[n - 2] - nums[2], nums[n - 1] - nums[3]});
    }
};
