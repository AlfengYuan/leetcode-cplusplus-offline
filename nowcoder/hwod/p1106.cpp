#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val('0'), left(nullptr), right(nullptr) {}
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {}
};

TreeNode* process(string& postOrder, int ps, int pe, string& inOrder, int is, int ie) {
    if (pe < ps || ie < is) return nullptr;
    TreeNode* root = new TreeNode(postOrder[pe]);
    int leftLen = 0;
    for (int i = is; i <= ie; i++) {
        if (inOrder[i] == postOrder[pe]) break;
        leftLen++;
    }

    root->left = process(postOrder, ps, ps + leftLen - 1, inOrder, is, is + leftLen - 1);
    root->right = process(postOrder, ps + leftLen, pe - 1, inOrder, is + leftLen + 1, ie);

    return root;
}

TreeNode* build(string& postOrder, string& inOrder) {
    return process(postOrder, 0, postOrder.length() - 1, inOrder, 0, inOrder.length() - 1);
}

string levelOrder(TreeNode* root) {
    if (!root) return "";
    queue<TreeNode*> myq;
    myq.push(root);
    string res = "";
    while (!myq.empty()) {
        TreeNode* curr = myq.front();
        res += curr->val;
        if (curr->left) myq.push(curr->left);
        if (curr->right) myq.push(curr->right);
        myq.pop();
    }

    return res;
}

int main(int argc, char* argv[]) {
    string postOrder, inOrder;
    cin >> postOrder >> inOrder;

    TreeNode* root = build(postOrder, inOrder);

    string result = levelOrder(root);

    cout << result << endl;

    return 0;
}