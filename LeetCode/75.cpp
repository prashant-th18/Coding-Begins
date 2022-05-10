class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0, o = 0, t = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) ++z;
            else if(nums[i] == 1) ++o;
            else ++t;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(z) nums[--z, i] = 0;
            else if(o) nums[--o, i] = 1;
            else nums[--t, i] = 2;
        }
    }
};
