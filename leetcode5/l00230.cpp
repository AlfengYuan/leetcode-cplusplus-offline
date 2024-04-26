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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> mystack;
        TreeNode *curr = root;
        int cnt = 0;
        while(curr || !mystack.empty()){
            while(curr){
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            mystack.pop();
            cnt++;
            if(cnt == k) return curr->val;
            curr = curr->right;
        }

        return -1;

    }

};