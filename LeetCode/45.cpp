using pii = pair<int, int>;
class Solution {
public:
    int jump0(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n + 1); // Steps needed to go from "i" to "n - 1"
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i) {
            for(int j = i + 1; j < min(n, i + nums[i] + 1); ++j) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        return dp[0];
    }
    int jump1(vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        vector<int> depth(n, n + 1);
        vector<bool> vis(n, false);
        q.push(0);
        depth[0] = 0; vis[0] = true;
        while(!q.empty() && depth[n - 1] != n + 1) {
           int ff = q.front(); q.pop();
           for(int i = ff + 1; i < min(n, ff + 1 + nums[ff]); ++i) {
               if(!vis[i]) q.push(i), vis[i] = true, depth[i] = depth[ff] + 1;
           }
        }
        return depth[n - 1];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        int level = 0, currentMax = 0, i = 0, nextMax = 0;
        while(1) {
            ++level;
            for(; i <= currentMax; ++i) {
                nextMax = max(nextMax, nums[i] + i);
                if(nextMax >= n - 1) return level;
            }
            currentMax = nextMax;
        }
    }
};
