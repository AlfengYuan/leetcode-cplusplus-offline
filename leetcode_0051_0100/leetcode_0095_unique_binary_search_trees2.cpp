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
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int l, int r)
    {
        if(l > r) return {nullptr};
        vector<TreeNode*> ans;
        for(int i = l; i<=r; i++)
        {
            vector<TreeNode *> lnodes = build(l, i-1);
            vector<TreeNode *> rnodes = build(i+1, r);
            for(int j = 0; j<lnodes.size(); j++)
            {
                for(int k = 0; k<rnodes.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnodes[j];
                    root->right = rnodes[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};