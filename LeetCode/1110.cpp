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
#define sz(x) ((int)x.size())
class Solution {
public:
    vector<TreeNode*> ans;
    vector<bool> del;
    TreeNode* dfs(TreeNode* root) {
        if(root -> left) {
            TreeNode* l = dfs(root -> left);
            root -> left = l;
        }
        if(root -> right) {
            TreeNode* r = dfs(root -> right);
            root -> right = r;
        }
        
        if(del[root -> val]) {
            if(root -> left) ans.push_back(root -> left);
            if(root -> right) ans.push_back(root -> right);
            return nullptr;
        }
        else return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        del.assign(1001, false);
        for(int i = 0; i < sz(d); ++i) {
            del[d[i]] = true;
        }
        root = dfs(root);
        if(root) ans.push_back(root);
        return ans;
    }
};
