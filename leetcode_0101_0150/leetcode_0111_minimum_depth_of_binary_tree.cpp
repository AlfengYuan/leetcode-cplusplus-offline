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
    int minDepth(TreeNode* root) {
        int result = 0;
        if(!root) return result;
        deque<TreeNode *> mydeque;
        mydeque.push_back(root);
        while(!mydeque.empty())
        {
            int currSize = mydeque.size();
            for(int i = 0; i<currSize; i++)
            {
                TreeNode *curr = mydeque.front();
                if(!curr->left && !curr->right) return result+1;
                if(curr->left) mydeque.push_back(curr->left);
                if(curr->right) mydeque.push_back(curr->right);
                mydeque.pop_front();
            }
            result++;
        }

        return result;
    }
};