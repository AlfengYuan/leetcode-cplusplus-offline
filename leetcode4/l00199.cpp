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
    vector<int> rightSideView(TreeNode* root) {
        return levelOrder(root);
    }

    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode *> myq;
        vector<int> res;
        if(!root) return res;
        myq.push(root);
        while(!myq.empty()){
            int n = myq.size();
            int val = 0;
            while(n--){
                TreeNode *curr = myq.front();
                val = curr->val;
                if(curr->left) myq.push(curr->left);
                if(curr->right) myq.push(curr->right);
                myq.pop();
            }
            res.push_back(val);
        }

        return res;
    }
};