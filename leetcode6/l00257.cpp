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
    vector<vector<int>> pathRes;
    vector<int> used;
public:
    void dfs(TreeNode* root, vector<int>& path) {
	
        path.push_back(root->val);
        if (!root->left && !root->right) {
            pathRes.push_back(path);
            return;
        }

        
        if (root->left) {
            dfs(root->left, path);
            path.pop_back();
        }

        if (root->right) {
            dfs(root->right, path);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, used);
        vector<string> currRes;
        for (auto& v : pathRes) {
            string tmp = "";
            for (int i = 0; i < v.size(); i++) {
                tmp += to_string(v[i]);
                if(i < v.size()-1) tmp += "->";
            }
            currRes.push_back(tmp);
        }
        return currRes;
    }
};