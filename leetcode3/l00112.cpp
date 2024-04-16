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
	bool dfs(TreeNode* root, vector<int>& path, int target) {
		if (!root) return false;
		path.push_back(root->val);
		if (!root->left && !root->right) {
			if (accumulate(path.begin(), path.end(), 0) == target) return true;
			else return false;
		}

		
		if (root->left) {
			if (dfs(root->left, path, target)) return true;;
			path.pop_back();
		}

		if (root->right) {
			if (dfs(root->right, path, target)) return true;
			path.pop_back();
		}

		return false;
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		vector<int> path;
		return dfs(root, path, targetSum);
	}
};