/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
/**
 * Definition for a binary tree node.*/
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode *root)
{
    cout << "[";
    if(!root) cout << "]" << endl;
    queue<TreeNode *> myqueue;
    myqueue.push(root);
    while(!myqueue.empty())
    {
        TreeNode *cur = myqueue.front();
        myqueue.pop();
        cout << cur->val << ", ";
        if(cur->left) myqueue.push(cur->left);
        if(cur->right) myqueue.push(cur->right);
    }
    cout << "]" << endl;
}



class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode *parent = nullptr, *right = nullptr;
        TreeNode *cur = root;
        while(cur)
        {
            TreeNode *next = cur->left;
            cur->left = right;
            right = cur->right;
            cur->right = parent;
            parent = cur;
            cur = next;
        }
        return parent;

    } 
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution = Solution();
    TreeNode *result = solution.upsideDownBinaryTree(root);
    printTree(result);

    return 0;
}