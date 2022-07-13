#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
#include <climits>
using namespace std;
/**
 * Definition for a binary tree node.*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        vector<int> ans;
        TreeNode *cur = root;
        stack<TreeNode *> stk;

        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top(); stk.pop();
            if (ans.size() > 0 && cur->val <= ans[ans.size() - 1]) return false;
            ans.push_back(cur->val);

            cur = cur->right;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    Solution solution = Solution();
    bool result = solution.isValidBST(root);
    
    if (result) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}