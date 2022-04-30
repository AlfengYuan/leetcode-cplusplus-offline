#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(string s, string p) {
        return MatchStr(s, p);
    }
};

int main(int argc, char *argv[])
{
    string s = "aa";
    string p = "a";
    Solution solution = Solution();
    bool res = solution.isMatch(s, p);
    if(res) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

