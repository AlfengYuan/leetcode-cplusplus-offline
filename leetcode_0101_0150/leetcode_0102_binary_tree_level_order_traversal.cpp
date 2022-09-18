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
        
        vector<vector<int>> result;
        if(!root) return result;
        deque<TreeNode *> mydeque;
        mydeque.push_back(root);
        while(!mydeque.empty())
        {
            vector<int> tmp;
            int currSize = mydeque.size();
            for(int i = 0; i<currSize; i++)
            {
                TreeNode *curr = mydeque.front();
                if(curr->left) mydeque.push_back(curr->left);
                if(curr->right) mydeque.push_back(curr->right);
                mydeque.pop_front();
                tmp.push_back(curr->val);
            }
            result.push_back(tmp);
        }

        return result;
    }
};