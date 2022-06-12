#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if 0
class Solution {
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root)
        {
            
            if(root->left) postorderTraversal(root->left);
            if(root->right) postorderTraversal(root->right);
            result.push_back(root->val);
        }
        
        return result;

    }
};
#endif

class Solution {
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        stack<TreeNode *> stk;

        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.push(cur);
                ans.push_back(cur->val);
                cur = cur->right;
            }
            cur = stk.top(); stk.pop();
            
            cur = cur->left;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution = Solution();
    vector<int> result = solution.postorderTraversal(root);
    cout << "[";
    for(int &i: result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;

    return 0;
}