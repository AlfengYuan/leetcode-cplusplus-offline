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
class BSTIterator {
    vector<int> res;
    int index = 0;
    int cap = 0;
public:
    BSTIterator(TreeNode* root) {
        if (!root) return;
        dfs(root);
        index = 0;
        cap = res.size();

    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }

    int next() {
        if (hasNext()) {
            return res[index++];
        }
        else {
            return -1;
        }
    }

    bool hasNext() {
        return index < cap;
    }


};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */