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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> myq;
        vector<vector<int>> res;
        if(!root) return res;
        myq.push(root);
        while(!myq.empty()){
            int n = myq.size();
            vector<int> tmp;
            while(n--){
                TreeNode *curr = myq.front();
                tmp.push_back(curr->val);
                if(curr->left) myq.push(curr->left);
                if(curr->right) myq.push(curr->right);
                myq.pop();
            }
            res.push_back(tmp);
        }

        return res;
    }
};