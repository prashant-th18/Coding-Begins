class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1, k = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1]) {
                if(++cnt <= 2) {
                    nums[k++] = nums[i];
                }
            }
            else {
                nums[cnt = 1, k++] = nums[i];
            }
        }
        return k;
    }
};
