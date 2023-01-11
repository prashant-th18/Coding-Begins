/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	map<TreeNode*, TreeNode*> par;
	map<TreeNode*, int> lvl;
	void dfs(TreeNode* root, TreeNode* p = nullptr, int l = 0) {
		par[root] = p;
		lvl[root] = l;
		if(root -> left) dfs(root -> left, root, l + 1);
		if(root -> right) dfs(root -> right, root, l + 1);
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
		if(lvl[p] > lvl[q]) swap(p, q);
		while(lvl[q] != lvl[p]) q = par[q];
		if(p == q) return p;
		while(par[p] != par[q]) p = par[p], q = par[q];
		return par[p];
    }
};
