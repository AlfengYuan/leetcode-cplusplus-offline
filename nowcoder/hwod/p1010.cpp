#include <vector>
#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {};
};

TreeNode *build(vector<int> &nums){
    vector<TreeNode *> myvec;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == -1) myvec.push_back(nullptr);
        else myvec.push_back(new TreeNode(nums[i]));
    }

    for(int i = 0; i<myvec.size(); i++){
        TreeNode *curr = myvec[i];
        if(curr){
            curr->left = 2*i + 1 < myvec.size() ? myvec[2*i+1] : nullptr;
            curr->right = 2*i + 2 < myvec.size() ? myvec[2*i+2] : nullptr;
        }
    }
    return myvec[0];
}

int private_talk(TreeNode *root){
    if(!root) return 0;
    return root->val + max(private_talk(root->left), private_talk(root->right));
}

int main(int argc, char *argv[]){
    int x;
    vector<int> nums;
    while(cin >> x){
        nums.push_back(x);
        if(cin.get() == '\n') break;
    }

    TreeNode *root = build(nums);

    int res = private_talk(root);

    cout << res << endl;

    return 0;
}