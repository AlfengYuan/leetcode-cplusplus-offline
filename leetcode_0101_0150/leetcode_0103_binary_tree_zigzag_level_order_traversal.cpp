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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        deque<TreeNode *> mydeque;
        mydeque.push_back(root);
        int depth = 0;
        while(!mydeque.empty())
        {
            vector<int> tmp;
            int currSize = mydeque.size();
            for(int i = 0; i<currSize; i++)
            {
                if(depth % 2 == 0)
                {
                    TreeNode *curr = mydeque.front();
                    mydeque.pop_front();
                    if(curr->left) mydeque.push_back(curr->left);
                    if(curr->right) mydeque.push_back(curr->right);
                    tmp.push_back(curr->val);
                }
                else
                {
                    TreeNode *curr = mydeque.back();
                    mydeque.pop_back();
                    if(curr->right) mydeque.push_front(curr->right);
                    if(curr->left) mydeque.push_front(curr->left);
                    tmp.push_back(curr->val);
                }
            }
            depth++;
            result.push_back(tmp);
        }

        return result;

    }
};