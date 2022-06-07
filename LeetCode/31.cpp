class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        for(int i = (int)nums.size() - 2; i >= 0; --i) {
            if(nums[i] < nums[nums.size() - 1]) {
                swap(nums[i], nums[nums.size() - 1]);
                s = i + 1;
                break;
            }
        }
        for(int i = s; i < e; ++i) {
            int mini = nums[i], ind = i;
            for(int j = i + 1; j <= e; ++j) {
                if(nums[j] < mini) mini = nums[j], ind = j;
            }
            swap(nums[i], nums[ind]);
        }
    }
};