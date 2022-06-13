#include <vector>
#include <stack>
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
class BSTIterator {
    vector<int> vec;
    int idx;
public:
    BSTIterator(TreeNode* root) :idx(0) {
        this->vec = this->inorderTraversal(root);
    }

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
    
    int next() {
        cout << this->vec[this->idx] << ", ";
        return this->vec[this->idx++];

    }
    
    bool hasNext() {
        if(this->idx == vec.size())
        {
            cout << "false, "; 
            return false;
        }
        cout << "true, ";
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *obj = new BSTIterator(root);
    cout << "[ null, ";
    obj->next();
    obj->next();
    obj->hasNext();
    obj->next();
    obj->hasNext();
    obj->next();
    obj->hasNext();
    obj->next();
    obj->hasNext();
    cout << "]" << endl;
    return 0;
    
}