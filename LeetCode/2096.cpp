class Solution {
public:
    vector<array<int, 3>> v; // parent, level, {-1 for parent's left, +1 for parent's right}
    int numberNodes(TreeNode* t) {
        if(t == nullptr) return 0;
        return 1 + numberNodes(t -> left) + numberNodes(t -> right);
    }
    void dfs(TreeNode* root, int level, int par) {
        v[root -> val][1] = level;
        v[root -> val][0] = par;
        if(root -> left) {
            v[root -> left -> val][2] = -1;
            dfs(root -> left, level + 1, root -> val);
        }
        if(root -> right) {
            v[root -> right -> val][2] = 1;
            dfs(root -> right, level + 1, root -> val);
        }
    }
    string getDirections(TreeNode* root, int sv, int dv) {
        int n = numberNodes(root);
        v.assign(n + 1, {-1, 0, -1});
        dfs(root, 0, -1);
        string source = "", dest = "";
        while(v[sv][1] != v[dv][1]) {
            if(v[sv][1] > v[dv][1]) {
                source += "U";
                sv = v[sv][0];
            }
            else if(v[sv][1] < v[dv][1]) {
                dest += ((v[dv][2] == -1) ? ("L") : ("R"));
                dv = v[dv][0];
            }
        }
        while(sv != dv) {
            source += "U";
            sv = v[sv][0];
            dest += ((v[dv][2] == -1) ? ("L") : ("R"));
            dv = v[dv][0];
        }
        reverse(dest.begin(), dest.end());
        source += dest;
        return source;
    }
};
