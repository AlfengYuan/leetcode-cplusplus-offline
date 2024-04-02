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
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> mystack;
        TreeNode* curr = root;

        while (curr || !mystack.empty())
        {
            while (curr) {
                mystack.push(curr);
                curr = curr->left;
            }

            curr = mystack.top();
            res.push_back(curr->val);
            mystack.pop();

            curr = curr->right;
        }

        return res;


    }
};