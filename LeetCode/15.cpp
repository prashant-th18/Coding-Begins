#include<map>
#define all(x) x.begin(), x.end()
const int N = 3e5;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(all(nums));
        nums.resize(unique(all(nums)) - nums.begin());
        vector<vector<vector<int>>> mp(6e5 + 1);
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                vector<int> v = {i, j};
                mp[N + nums[i] + nums[j]].push_back(v);
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            int s = -nums[i];
            vector<vector<int>> &temp = mp[N + s];
            int ind = temp.size(), si = 0, ei = temp.size() - 1;
            while(si <= ei) {
                int mid = (si + ei) >> 1;
                if(temp[mid][0] > i) {
                    ind = mid; ei = mid - 1;
                }
                else si = mid + 1;
            }
            for(int j = ind; j < temp.size(); ++j) {
                vector<int> a = {nums[i], nums[temp[j][0]], nums[temp[j][1]]};
                sort(begin(a), end(a));
                ans.push_back(a);
            }
        }
        sort(all(ans));
        ans.resize(unique(all(ans)) - ans.begin());
        return ans;
    }
};
