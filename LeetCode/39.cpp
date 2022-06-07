class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<int>> ans;
    vector<int> v;
    vector<int> c;
    void check(int index, int target) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        if(index == 0) return;
        // Not taking this one
        check(index - 1, target);

        // Taking this one
        v.push_back(c[index - 1]);
        check(index, target - c[index - 1]);
        v.pop_back();
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        c = candidates;
        dp.assign(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= target; ++j) {
                if(j == 0) dp[i][j] = true;
                else {
                    dp[i][j] = dp[i - 1][j];
                    if(j >= candidates[i - 1]) dp[i][j] = dp[i][j] | dp[i][j - candidates[i - 1]];
                }
            }
            v.push_back(candidates[i - 1]);
            check(i, target - candidates[i - 1]);
            v.pop_back();
        }
        return ans;
    }
};