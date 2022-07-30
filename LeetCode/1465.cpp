#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;
class Solution {
public:
    int maxArea(int H, int W, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        int l1 = max(h[0], H - h[sz(h) - 1]);
        int l2 = max(v[0], W - v[sz(v) - 1]);
        for(int i = 1; i < sz(h); ++i) l1 = max(l1, h[i] - h[i - 1]);
        for(int i = 1; i < sz(v); ++i) l2 = max(l2, v[i] - v[i - 1]);
        return 1LL * l1 * l2 % MOD;
    }
};
