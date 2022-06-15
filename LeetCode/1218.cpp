class Solution {
public:
    int longestSubsequence(vector<int>& v, int d) {
        vector<int> mp(4e4 + 1, 0);
        int maxx = -1;
        for(int i = v.size() - 1; i >= 0; --i) {
            maxx = max(maxx, mp[v[i] + 20000] = 1 + mp[v[i] + d + 20000]);
        }
        return maxx;
    }
};

