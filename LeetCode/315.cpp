#define ss second
#define ff first
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> v(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            v[i] = pair(nums[i], i);
        }
        sort(v.begin(), v.end());
        int n = nums.size();
        vector<int> hash(n);
        for(int i = 0; i < n; ++i) {
            hash[v[i].ss] = i + 1;
        }
        vector<int> bit(n + 1, 0);
        auto upd = [&](int ind) {
            for(; ind <= n; ind += (ind & -ind)) {
                bit[ind] += 1;
            }
        };
        auto sum = [&](int in) {
            int s = 0;
            for(; in > 0; in -= in & -in) s += bit[in];
            return s;
        };
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i) {
            ans[i] = sum(hash[i]);
            upd(hash[i]);
        }
        return ans;
    }
};
