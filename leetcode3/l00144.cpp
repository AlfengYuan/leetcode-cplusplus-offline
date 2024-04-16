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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode *> mystack;
        vector<int> res;
        TreeNode *curr = root;
        while(curr || !mystack.empty()){
            while(curr){
                res.push_back(curr->val);
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            mystack.pop();
            curr = curr->right;
        } 

        return res;
    }
};