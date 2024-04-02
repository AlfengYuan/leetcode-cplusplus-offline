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
    bool isValidBST(TreeNode* root) {
        vector<int> in = inOrder(root);
        for(int i = 1; i<in.size(); i++){
            if(in[i] <= in[i-1]) return false;
        }

        return true;
    }

    vector<int> inOrder(TreeNode *root){
        stack<TreeNode *> mystack;
        TreeNode *curr = root;
        vector<int> res;
        while(curr || !mystack.empty()){
            while(curr){
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top(); mystack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }
};