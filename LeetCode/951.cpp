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
class Solution {
public:
    int cnt(TreeNode* r) {
        return (r -> left != nullptr) + (r -> right != nullptr);
    }
    bool dfs(TreeNode* r1, TreeNode* r2) {
        if((r1 && !r2) || (!r1 && r2)) return false;
        if(!r1 && !r2) return true;
        // r1 & r2 are valid
        if(r1 -> val != r2 -> val) return false;
        int c1 = cnt(r1), c2 = cnt(r2);
        if(c1 != c2) return false;
        if(c1 == 2) {
            if(r1 -> left -> val == r2 -> left -> val) {
                return dfs(r1 -> left, r2 -> left) && dfs(r1 -> right, r2 -> right);
            }
            else return dfs(r1 -> left, r2 -> right) && dfs(r1 -> right, r2 -> left);
        }
        else if(c1 == 1) {
            TreeNode* t1 = r1 -> left; if(!t1) t1 = r1 -> right;
            TreeNode* t2 = r2 -> left; if(!t2) t2 = r2 -> right;
            return dfs(t1, t2);
        }
        return true;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};
