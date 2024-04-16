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
	void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& vec, int target) {
		
		path.push_back(root->val);
		if (!root->left && !root->right) {
			if (accumulate(path.begin(), path.end(), 0) == target) {
				vec.push_back(path);
			}
		}

		if (root->left) {
			dfs(root->left, path, vec, target);
			path.pop_back();
		}

		if (root->right) {
			dfs(root->right, path, vec, target);
			path.pop_back();
		}
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> vec;
		if (!root) return {};
		vector<int> path;
		dfs(root, path,vec, targetSum);
		return vec;
	}
};