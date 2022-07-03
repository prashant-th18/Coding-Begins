const int MOD = (1e9 + 7);
class Solution {
public:
    void add(int& a, int b) {
        a = (a + b) % MOD;
    }
    int checkRecord(int n) {
        vector<vector<int>> dp(n + 3, vector<int>(7, 0));
        // p 0, ll 1, l 2, a 3, ap 4, all 5, al 6
        for(int i = n; i < n + 3; ++i) {
            auto& mp = dp[i];
            mp[0] = mp[1] = mp[2] = mp[3] = mp[4] = mp[5] = mp[6] = 0;
        }
        auto& l = dp[n - 1];
        l[0] = l[3] = l[2] = 1;
        vector<int> h = {0, 1, 2};
        for(int i = n - 2; i >= 0; --i) {
            auto& mp = dp[i];
            // No absent
            for(auto val : h) {
                add(mp[0], dp[i + 1][val]);
            }
            add(mp[1], dp[i + 1][2]);
            add(mp[2], dp[i + 1][0]);
            // Absent
            for(auto val : h) {
                add(mp[3], dp[i + 1][val]);
            }
            for(auto val : h) {
                int res = 4 + val;
                add(mp[4], dp[i + 1][res]);
            }
            add(mp[4], dp[i + 1][3]);
            add(mp[5], dp[i + 1][6]);
            add(mp[6], dp[i + 1][4]);
            add(mp[6], dp[i + 1][3]);
        }
        int ans = 0;
        vector<int> he(7, 0); iota(he.begin(), he.end(), 0);
        for(auto val : he) {
            add(ans, dp[0][val]);
        }
        return ans;
    }
};
