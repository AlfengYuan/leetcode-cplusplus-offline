
#include <cstdlib>
#include <iostream>
#include <vector>
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
class Solution {
    vector<int> result;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root)
        {
            result.push_back(root->val);
            if(root->left) preorderTraversal(root->left);
            if(root->right) preorderTraversal(root->right);
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution = Solution();
    vector<int> result = solution.preorderTraversal(root);
    cout << "[";
    for(int &i: result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;

    return 0;
}