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
    void flatten(TreeNode* root) {
        vector<TreeNode *> preorder = preorderTraversal(root);
        for(int i = 1; i<preorder.size(); i++)
        {
            root->left = nullptr;
            root->right = preorder[i];
            root = root->right;
        }
    }

    vector<TreeNode *> preorderTraversal(TreeNode* root) {
        vector<TreeNode *> ans;
        TreeNode *cur = root;
        stack<TreeNode *> stk;

        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.push(cur);
                ans.push_back(cur);
                cur = cur->left;
            }
            cur = stk.top(); stk.pop();
            cur = cur->right;
        }
        return ans;
    }
};