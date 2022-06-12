/**
 * Definition for a binary tree node.*/

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root)
        {
            
            if(root->left) inorderTraversal(root->left);
            result.push_back(root->val);
            if(root->right) inorderTraversal(root->right);
        }
        
        return result;

    }
};
#endif

class Solution {
public:
/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        stack<TreeNode *> stk;

        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
        
            cur = stk.top(); stk.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution = Solution();
    vector<int> result = solution.inorderTraversal(root);
    cout << "[";
    for(int &i: result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;

    return 0;
}