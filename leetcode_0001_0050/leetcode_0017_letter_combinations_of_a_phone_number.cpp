#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<string> ans;
    string strs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string &digits, int idx, string combine)
    {
        if(idx == digits.length())
        {
            ans.push_back(combine);
            return;
        }
        string s = strs[digits[idx] - '0'];
        for(int i = 0; i<s.length(); ++i)
        {
            combine.push_back(s[i]);
            dfs(digits, idx+1, combine);
            combine.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    string digits = "23";
    Solution solution = Solution();
    vector<string> res = solution.letterCombinations(digits);
    cout << "[";
    for(string &s:res)
    {
        cout << "\"" << s << "\"" << ", ";
    }
    cout << "]" << endl;
    return 0;
}