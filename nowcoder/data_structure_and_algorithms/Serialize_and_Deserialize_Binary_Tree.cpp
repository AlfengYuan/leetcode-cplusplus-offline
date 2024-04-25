// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/description/
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
    
public:
 
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string str = "";
        if (!root) return str;
        vector<TreeNode *> result;
        vector<TreeNode *> mydeque;
        mydeque.push_back(root);
        int left = 0;
        int right = mydeque.size();
        bool flag = true;
        while (left < right && flag)
        {
            for (int i = left; i < right; i++)
            {
                TreeNode *curr = mydeque[i];
                if (curr)
                {
                    if (curr->left) mydeque.push_back(curr->left);
                    else mydeque.push_back(NULL);
                    if (curr->right) mydeque.push_back(curr->right);
                    else mydeque.push_back(NULL);
                }
                result.push_back(curr);
                flag = false;
                for (vector<TreeNode *>::iterator iter = mydeque.begin() + right; iter != mydeque.end(); iter++)
                {
                    if (*iter != NULL)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            left = right;
            right = mydeque.size();
        }
 
        right = result.size() - 1;
        while (!result[right]) right--;
        str += "[";
        for (int i = 0; i < right; i++)
        {
            if (result[i])
            {
                str += to_string(result[i]->val) + ", ";
            }
            else
            {
                str += "null, ";
            }
        }
        str += to_string(result[right]->val);
        str += "]";
 
        return str;
    }
 
 
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.length() == 0) return NULL;
        string cstr = data.substr(1, data.length() - 2);
        vector<string> vec;
        char *token = strtok(cstr.data(), ", "); // non-const data() needs c++17
        while (token != NULL)
        {
            vec.push_back(token);
            token = strtok(NULL, ", ");
        }
 
        return build(vec);
    }
 
    bool isNumber(string s) {
        vector<bool> flag(3, false);  //['+/-', '.', 'e/E']
        if (s == ".") return false;
        if (s[0] == '.') flag[1] = true;
        if (isalpha(s[0]) && tolower(s[0]) != 'e') return false;
        if (tolower(s[0]) == 'e' || tolower(s[s.length() - 1]) == 'e') return false;
        if (s[0] == '+' || s[0] == '-')
        {
            if (s.length() <= 1) return false;
            flag[0] = true;
        }
        for (int i = 1; i < s.length(); i++)
        {
            if (isdigit(s[i])) continue;
            else if (tolower(s[i]) == 'e')
            {
                if (i == 1 && (s[i - 1] == '.' || s[i - 1] == '+' || s[i - 1] == '-')) return false;
                else if (flag[2] == true) return false;
                else flag[2] = true;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (tolower(s[i - 1]) != 'e') return false;
                else if (i == s.length() - 1) return false;
 
            }
            else if (s[i] == '.')
            {
                if (flag[1] == true || flag[2] == true) return false;
                else if (flag[0])
                {
                    if ((i == s.length() - 1) && (s[i - 1] == '-' || s[i - 1] == '+')) return false;
                }
                flag[1] = true;
            }
            else if (isalpha(s[i]))
            {
                return false;
            }
 
        }
        return true;
    }
 
    TreeNode *build(vector<string> &vec)
    {
        vector<TreeNode *> vecp;
        for (int i = 0; i < vec.size(); i++)
        {
            if (isNumber(vec[i]))
            {
                vecp.push_back(new TreeNode(atoi(vec[i].c_str())));
            }
            else
            {
                vecp.push_back(NULL);
            }
        }
        TreeNode *result = vecp[0];
        int left = 0, right = 1;
        while (right < vecp.size())
        {
            if (vecp[left])
            {
                vecp[left]->left = vecp[right++];
                if (right < vecp.size())
                {
                    vecp[left]->right = vecp[right++];
                }
            }
            left++;
 
        }
        return result;
 
    }
};
 
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(int argc, char *argv[]){
    // [1,5,3,null,4,10,6,9,2]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    Codec ser, deser;
    string res = ser.serialize(root);
    cout << res << endl;

    string ts = "[1,2,3,null,null,4,5]";
    TreeNode *tree = deser.deserialize(ts);
    cout << "[";
    cout << tree->val << ",";
    cout << tree->left->val << ",";
    cout << tree->right->val << ",";
    cout << "null" << ",";
    cout << "null" << ",";
    cout << tree->right->left->val << ",";
    cout << tree->right->right->val;
    cout << "]";
    cout << endl;

    
    


    return 0;
}