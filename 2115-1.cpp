class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string, vector<int>> mp;
        vector<int> in(ing.size(), 0);
        for(int i = 0; i < ing.size(); ++i) {
            auto v = ing[i];
            for(auto& val : v) {
                mp[val].push_back(i);
                ++in[i];
            }
        }
        queue<string> q;
        for(auto& v: sup) q.push(v);
        vector<string> ans;
        while(!q.empty()) {
            string f = q.front(); q.pop();
            for(auto val : mp[f]) {
                --in[val];
                if(in[val] == 0) {
                    ans.push_back(rec[val]);
                    q.push(rec[val]);
                }
            }
        }
        return ans;
    }
};
