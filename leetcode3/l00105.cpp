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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode *build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie){
        if(pe < ps || ie < is) return nullptr;
        TreeNode *root = new TreeNode(preorder[ps]);
        int leftLen = 0;
        for(int i = is; i<=ie; i++){
            if(inorder[i] == preorder[ps]) break;
            else {
                leftLen++;
            }
        }
        root->left = build(preorder, ps+1, ps+leftLen, inorder, is, is+leftLen-1);
        root->right = build(preorder, ps+leftLen+1, pe, inorder, is+leftLen+1, ie);

        return root;
    }
};