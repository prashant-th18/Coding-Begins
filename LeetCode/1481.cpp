#define ss second
#define sz(x) ((int)x.size())
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& v, int k) {
        map<int, int> mp;
        for (int i = 0; i < v.size(); i++) {
            mp[v[i]]++;
        }
        vector<int> ans;
        for(auto& val : mp) ans.push_back(val.ss);
        sort(ans.begin(), ans.end());
        int u = sz(mp);
        for(int i = 0; i < ans.size(); ++i) {
            if(k >= ans[i]) u--, k -= ans[i];
            else break;
        }
        return u;
    }
};
