#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int i = s.length() - 1;
        while(i>= 0 && s[i] == ' ') --i;
        while(i >= 0 && s[i--] != ' ') ++res;
        return res;
    }
};

int main(int argc, char *argv[])
{
    string s = "Hello World";
    Solution solution = Solution();
    int res = solution.lengthOfLastWord(s);
    cout << res << endl;
    return 0;
}