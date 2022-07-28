class Solution {
public:
    int numSplits(string s) {
        int left = 0, right = 0;
        vector<int> l(26, 0), r(26, 0);
        for(int i = 0; i < s.size(); ++i) {
            int index = s[i] - 'a';
            if(r[index] == 0) {
                ++right;
            }
            r[index]++;
        }
        int ans = 0; // Keeps the good split
        for(int i = 0; i < s.size() - 1; ++i) {
            int index = s[i] - 'a';
            if(l[index] == 0) {
                ++left;
            }
            l[index]++;
            --r[index];
            if(r[index] == 0) --right;
            ans += (left == right);
        }
        return ans;
    }
};
