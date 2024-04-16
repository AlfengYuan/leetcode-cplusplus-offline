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
    vector<TreeNode *> vec;
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
        for(int i = 0; i<vec.size()-1; i++){
            vec[i]->left = nullptr;
            vec[i]->right = vec[i+1];
        }
        vec[vec.size()-1]->left = nullptr;
        vec[vec.size()-1]->right = nullptr;
    }

    void dfs(TreeNode *root){
        if(!root) return;
        vec.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
};