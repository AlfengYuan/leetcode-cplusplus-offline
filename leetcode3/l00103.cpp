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
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> myq;
        myq.push(root);
        int level = 1;
        while (!myq.empty()) {
            int n = myq.size();
            vector<int> tmp;
            while (n--) {
                TreeNode* curr = myq.front();
                tmp.push_back(curr->val);
                if (curr->left) myq.push(curr->left);
                if (curr->right) myq.push(curr->right);
                myq.pop();
            }
            if (level % 2 != 0) res.push_back(tmp);
            else {
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }
            level++;
        }

        return res;
    }
};