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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode *> mystack;
        TreeNode *curr = root;
        vector<int> res;
        while(curr || !mystack.empty()){
            while(curr){
                mystack.push(curr);
                res.push_back(curr->val);
                curr = curr->right;
            }

            curr = mystack.top();
            mystack.pop();
            curr = curr->left;
        }

        reverse(res.begin(), res.end());
        return res;

    }
};