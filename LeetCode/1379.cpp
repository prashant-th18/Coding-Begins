/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
class Solution {
public:
    string res = "";
    bool getString(TreeNode* orig, TreeNode* tar) {
        if(orig == nullptr) return false;
        if(tar == orig) {
            return true;
        }
        if(orig -> left && getString(orig -> left, tar)) {
            res += "l";
            return true;
        }
        if(orig -> right && getString(orig -> right, tar)) {
            res += "r";
            return true;
        }
        return false;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        getString(original, target);
        TreeNode* root = cloned;
        reverse(res.begin(), res.end());
        for(int i = 0; i < res.size(); ++i) {
            if(res[i] == 'l') root = root -> left;
            else root = root -> right;
        }
        return root;
    }
};
