class Solution {
public:
    vector<int> targetIndices(vector<int>& v, int t) {
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            if(v[i] == t) ans.push_back(i);
        }
        return ans;
    }
};
