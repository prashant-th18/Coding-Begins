#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ind(256, -1); // -1 tells not encountered
        int maxx = 0, start = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(ind[s[i]] > start) {
                start = ind[s[i]];
            }
            ind[s[i]] = i;
            maxx = max(maxx, (i) - start);
        }
        return maxx;
    }
};
int main() {
    Solution s;
    s.lengthOfLongestSubstring(string("tmmzuxt"));
    return 0;
}
