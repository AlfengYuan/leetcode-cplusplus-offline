#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() <= 1) return strs[0];
        string res = "";
        for(int i = 0; i<strs[0].length(); i++)
        {
            for(int j = 1; j<strs.size(); j++)
            {
                if(strs[j].length() == i || strs[j][i] != strs[0][i]) return res;
            }
            res += strs[0][i];
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution solution = Solution();
    string res = solution.longestCommonPrefix(strs);
    cout << res << endl;
    return 0;
}