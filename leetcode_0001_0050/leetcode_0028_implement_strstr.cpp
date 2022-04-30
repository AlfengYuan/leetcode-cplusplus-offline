#include <string>
#include <cstring>
#include <iostream>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        else if(haystack.length() == needle.length())
        {
            if(strcmp(haystack.c_str(), needle.c_str()) == 0)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            for(int i = 0; i<haystack.length() - needle.length()+1; i++)
            {
                int j = 0;
                int i_index = i;
                for(; j < needle.length(); j++)
                {
                    if(haystack[i_index] == needle[j])
                    {
                        i_index++;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                if(j == needle.length()) return i;

            }
            return -1;
        }
    }
};

int main(int argc, char *argv[])
{
    string haystack = "hello";
    string needle = "ll";
    Solution solution = Solution();
    int res = solution.strStr(haystack, needle);
    cout << res << endl;
    return 0;
}