class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + v[i];
        }
        int maxx = pre[n] - pre[n - k];
        for(int i = 0; i < k; ++i) {
            maxx = max(maxx, pre[i + 1] + (pre[n] - pre[n - (k - i - 1)]));
        }
        return maxx;
    }
};
