class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> st;
        int i = 0, j = 0;
        while(j < k - 1) {
            st.insert(nums[j++]);
        }
        vector<int> ans;
        while(j < nums.size()) {
            st.insert(nums[j++]);
            ans.push_back(*st.begin());
            st.erase(st.find(nums[i++]));
        }
        return ans;
    }
};
