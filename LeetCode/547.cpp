class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rank(n, 1);
        vector<int> par(n, -1);
        auto find = [&](int a) -> int {
            vector<int> t;
            while(par[a] != -1) {
                t.push_back(a);
                a = par[a];
            }
            for(auto& val : t) par[val] = a;
            return a;
        };
        auto un = [&](int a, int b) -> void {
            a = find(a);
            b = find(b);
            if(a == b) return;
            if(rank[a] > rank[b]) {
                rank[a] += rank[b];
                par[b] = a;
            }
            else {
                rank[b] += rank[a];
                par[a] = b;
            }
        };
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(mat[i][j] == 1) {
                    un(i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (par[i] == -1);
        }
        return ans;
    }
};
