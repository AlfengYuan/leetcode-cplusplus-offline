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
    TreeNode *first = nullptr, *second = nullptr;
public:
    void recoverTree(TreeNode* root) {
        TreeNode *last = nullptr, *cur = root;
        while(cur)
        {
            if(!cur->left)
            {
                check(last, cur);
                last = cur;
                cur = cur->right;

            }else{
                TreeNode *p = cur->left;
                while(p->right && p->right != cur) p = p->right;

                if(!p->right)
                {
                     p->right = cur;
                     cur = cur->left;
                }
                else
                {
                    p->right = nullptr;
                    check(last, cur);
                    last = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }

    void check(TreeNode *last, TreeNode *cur)
    {
        if(last && last->val > cur->val)
        {
            if(!first) first = last, second = cur;
            else second = cur;
        }
    }
};