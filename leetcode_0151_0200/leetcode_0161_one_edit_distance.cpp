#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s == t) return false;
        int sLen = s.length(), tLen = t.length();
        if(abs(sLen-tLen) <= 1)
        {
            if(sLen == tLen)
            {
                for(int i = 0; i<sLen; i++)
                {
                    if(s[i] != t[i])
                    {
                        t[i] = s[i];
                        break;
                    }
                }
            }
            else if(sLen > tLen)
            {
                for(int i = 0; i<sLen; i++)
                {
                    if(s[i] != t[i])
                    {
                        t.insert(i, string(1, s[i]));
                        break;
                    }
                }
            }
            else
            {
                for(int i = 0; i<tLen; i++)
                {
                    if(s[i] != t[i])
                    {
                        s.insert(i, string(1, t[i]));
                        break;
                    }
                }

            }

        }

        if(s == t) return true;
        else return false;
    }
};

int main(int argc, char *argv[])
{
    string s = "ab";
    string t = "acb";

    Solution solution = Solution();
    bool result = solution.isOneEditDistance(s, t);
    if(result) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}