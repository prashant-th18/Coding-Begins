class Solution {
public:
    int ans = 0;
    vector<int> ti;
    vector<vector<int>> v;
    void dfs(int node, int t, int p = -1) {
        t += ti[node];
        ans = max(ans, t);
        for(const auto& val : v[node]) {
            if(val != p) dfs(val, t, node);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        ti = informTime;
        v.assign(n, vector<int>());
        for(int i = 0; i < manager.size(); ++i) {
            int t = manager[i];
            if(t == -1) continue;
            v[t].push_back(i);
            v[i].push_back(t);
        }
        dfs(headID, 0);
        return ans;
    }
};
