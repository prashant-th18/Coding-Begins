using ll = long long;
class Solution {
public:
    ll maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<ll>> dp(n, vector<ll>(m, LLONG_MIN));
        decltype(dp) left(n, vector<ll>(m, LLONG_MIN));
        decltype(dp) right(n, vector<ll>(m, LLONG_MIN));
        for(int j = 0; j < m; ++j) {
            dp[0][j] = points[0][j];
        }
        for(int i = 1; i < n; ++i) {
            ll l = dp[i - 1][0];
            for(int j = 0; j < m; ++j) {
                l = max(l, dp[i - 1][j]);
                left[i - 1][j] = l;
                --l;
            }
            ll r = dp[i - 1][m - 1];
            for(int j = m - 1; j >= 0; --j) {
                r = max(r, dp[i - 1][j]);
                right[i - 1][j] = r;
                --r;
            }
            for(int j = 0; j < m; ++j) {
                dp[i][j] = points[i][j] + max(left[i - 1][j], right[i - 1][j]);
            }
        }
        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
