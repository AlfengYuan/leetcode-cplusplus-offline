#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == 'M')
            {
                res += 1000;
            }
            else if(s[i] == 'C' && i+1 < s.length() && s[i+1] == 'M')
            {
                res += 900;
                i++;
            }
            else if(s[i] == 'C' && i+1 < s.length() && s[i+1] == 'D')
            {
                res += 400;
                i++;
            }
            else if(s[i] == 'D')
            {
                res += 500;
            }
            else if(s[i] == 'C')
            {
                res += 100;
            }
            else if(s[i] == 'X' && i+1 < s.length() && s[i+1] == 'C')
            {
                res += 90;
                i++;
            }
            else if(s[i] == 'X' && i+1 < s.length() && s[i+1] == 'L')
            {
                res += 40;
                i++;
            }
            else if(s[i] == 'L')
            {
                res += 50;
            }
            else if(s[i] == 'X')
            {
                res += 10;
            }
            else if(s[i] == 'I' && i+1 < s.length() && s[i+1] == 'X')
            {
                res += 9;
                i++;
            }
            else if(s[i] == 'I' && i+1 < s.length() && s[i+1] == 'V')
            {
                res += 4;
                i++;
            }
            else if(s[i] == 'V')
            {
                res += 5;
            }
            else if(s[i] == 'I')
            {
                res += 1;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    string s = "III";
    Solution solution = Solution();
    int res = solution.romanToInt(s);
    cout << res << endl;
    return 0;
}