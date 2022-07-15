/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int N = 100001;
class Solution {
public:
    // All values are from 1 to n
    vector<int> level;
    vector<int> par;
    void dfs(TreeNode* root, int p, int l) {
        level[root -> val] = l;
        par[root -> val] = p;
        if(root -> left) dfs(root -> left, root -> val, l + 1);
        if(root -> right) dfs(root -> right, root -> val, l + 1);
    }
    TreeNode* getNode(TreeNode* root, int sv) {
        if(root -> val == sv) return root;
        if(root -> left) {
            TreeNode* temp = getNode(root -> left, sv);
            if(temp) return temp;
        }
        if(root -> right) {
            TreeNode* temp = getNode(root -> right, sv);
            if(temp) return temp;
        }
        return nullptr;
    }
    string getDirections(TreeNode* root, int sv, int dv) {
        level.assign(N, 0);
        par.assign(N, -1);
        dfs(root, -1, 0);
        string res = "";
        vector<int> d;
        while(level[sv] != level[dv]) {
            if(level[sv] > level[dv]) {
                res += "U";
                sv = par[sv];
            }
            else {
                d.push_back(dv);
                dv = par[dv];
            }
        }
        while(sv != dv) {
            res += "U";
            sv = par[sv];
            d.push_back(dv);
            dv = par[dv];
        }
        TreeNode* st = getNode(root, sv);
        reverse(d.begin(), d.end());
        for(int i = 0; i < d.size(); ++i) {
            if(st -> left && st -> left -> val == d[i]) {
                res += "L";
                st = st -> left;
            }
            else {
                res += "R";
                st = st -> right;
            }
        }
        return res;
    }
};
