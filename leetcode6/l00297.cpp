/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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