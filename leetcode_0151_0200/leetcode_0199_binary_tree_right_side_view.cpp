#include <vector>
#include <iostream>
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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode *> tmp;
        vector<vector<TreeNode *>> vec;
        if(!root) return ans;
        tmp.push_back(root);
        vec.push_back(tmp);
        tmp.clear();
        for(int i = 0; i<vec.size(); i++)
        {
            int j = 0;
            for(; j<vec[i].size(); j++)
            {
                if(vec[i][j]->left) tmp.push_back(vec[i][j]->left);
                if(vec[i][j]->right) tmp.push_back(vec[i][j]->right);
            }
            if(j != 0) 
            {
                ans.push_back(vec[i][j-1]->val);
                vec.push_back(tmp);
                tmp.clear();
            }
        }

        return ans;

    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution = Solution();
    vector<int> result = solution.rightSideView(root);

    cout << "[";
    for(int &i: result)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;

    return 0;
}