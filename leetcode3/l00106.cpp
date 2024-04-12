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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildIP(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildIP(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        if (ie < is || pe < ps) return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int leftLen = 0;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == postorder[pe]) break;
            else {
                leftLen++;
            }
        }

        root->left = buildIP(inorder, is, is+leftLen-1, postorder, ps, ps+leftLen-1);
        root->right = buildIP(inorder, is+leftLen+1, ie, postorder, ps+leftLen, pe - 1);

        return root;
    }
};