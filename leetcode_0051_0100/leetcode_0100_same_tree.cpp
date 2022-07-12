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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool result = false;
        if (p && q)
        {
            if (p->val == q->val)
            {
                result |= isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            else
            {
                return false;
            }
        }
        else
        {
            if ((p && !q) || (q && !p)) return false;
            if (!p && !q) return true;
        }

        return result;
    }
};
int main(int argc, char* argv[])
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);

    Solution solution = Solution();
    bool result = solution.isSameTree(p, q);
    
    if (result) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}