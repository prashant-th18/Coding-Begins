class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        vector<int> in(n, 0);
        for(int i = 0; i < p.size(); ++i) {
            v[p[i][0]].push_back(p[i][1]);
            ++in[p[i][1]];
        }
        int ans = 0;
        queue<int> q;
        for(int i = 0; i < n; ++i) if(in[i] == 0) q.push(i);
        while(!q.empty()) {
            int t = q.front(); q.pop();
            ++ans;
            for(const auto& val : v[t]) {
                --in[val];
                if(in[val] == 0) q.push(val);
            }
        }
        return ans == n;
    }
};
