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
	void dfs(TreeNode* root, int path, vector<int>& vec) {
        path = path * 10 + root->val;
		if (!root->left && !root->right) {
			vec.push_back(path);
		}

		if (root->left) {
			dfs(root->left, path, vec);
		}

		if (root->right) {
			dfs(root->right, path, vec);
		}
	}

    int sumNumbers(TreeNode* root) {
        vector<int> vec;
        if(!root) return 0;
        dfs(root, 0, vec);
        return accumulate(vec.begin(), vec.end(), 0);
    }
};