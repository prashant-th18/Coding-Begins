#define all(x) x.begin(), x.end()
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
        vector<vector<int>> v(26);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'].push_back(i);
        }
        int ans {};
        for(const auto& val : w) {
            int ind = -1;
            bool f = true;
            for(const auto& vall : val) {
                ind = upper_bound(all(v[vall - 'a']), ind) - begin(v[vall - 'a']);
                if(ind == v[vall - 'a'].size()) {
                    f = false; break;
                }
                ind = v[vall - 'a'][ind];
            }
            if(f) ++ans;
        }
        return ans;
    }
};
