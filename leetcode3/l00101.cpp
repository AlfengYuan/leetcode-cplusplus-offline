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
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return compare(root->left, root->right);
	}

	bool compare(TreeNode* left, TreeNode* right) {
		if (!left && right) return false;
		if (left && !right) return false;
		if (!left && !right) return true;
		if (left->val != right->val) return false;
		
		return compare(left->left, right->right) && compare(left->right, right->left);
	}
};