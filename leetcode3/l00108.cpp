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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        int index = nums.size() / 2;
        int val = nums[index];
        TreeNode *root = new TreeNode(val);
        vector<int> lv;
        lv.assign(nums.begin(), nums.begin()+index);
        vector<int> rv;
        rv.assign(nums.begin()+index+1, nums.end());
        root->left = sortedArrayToBST(lv);
        root->right = sortedArrayToBST(rv);

        return root;

    }
};