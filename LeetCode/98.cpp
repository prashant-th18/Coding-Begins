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
    vector<int> dfs(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        vector<int> left = dfs(root -> left);
        vector<int> right = dfs(root -> right);
        if(root -> left && root -> right) {
            if(left[2] == 1 && right[2] == 1 && left[1] < root -> val && root -> val < right[0]) {
                ans.push_back(left[0]);
                ans.push_back(right[1]);
                ans.push_back(1);
            }
            else {
                ans = {0, 0, 0};
            }
        }
        else if(root -> left) {
            if(left[2] == 1 && left[1] < root -> val) {
                ans.push_back(left[0]);
                ans.push_back(root -> val);
                ans.push_back(1);
            }
            else {
                ans = {0, 0, 0};
            }
        }
        else if(root -> right) {
            if(right[2] == 1 && root -> val < right[0]) {
                ans.push_back(root -> val);
                ans.push_back(right[1]);
                ans.push_back(1);
            }
            else ans = {0, 0, 0};
        }
        else {
            ans = {root -> val, root -> val, 1};
        }
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        // return dfs(root)[2] == 1;
        return Valid(root, nullptr, nullptr);
    }
    bool Valid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root -> val <= minNode -> val || maxNode && root -> val >= maxNode -> val) {
             return false;
        }
        return Valid(root -> left, minNode, root) && Valid(root -> right, root, maxNode);
    }
};
