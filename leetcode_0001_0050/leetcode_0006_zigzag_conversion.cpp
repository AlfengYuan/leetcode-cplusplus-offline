#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || s.length() <= 1) return s;
        vector<string> vecRes(numRows);
        string res = "";
        int row = -2;
        bool dir = true;
        for(int i = 0; i<s.length(); ++i)
        {
            if(dir == true && row < numRows-1)
            {
               if(row <= -1) ++row;
               vecRes[++row] += s[i];
            }
            else if(dir == false && row > -1)
            {
                if(row == numRows) --row;
                vecRes[--row] += s[i]; 
            }

            if(dir == true && row == numRows-1)
            {
                dir = false;
            }
            else if(dir == false && row == 0)
            {
                dir = true;
            }          
        }

        for(int i = 0; i<numRows; i++)
        {
            res += vecRes[i];
        }
        return res;

    }
};

int main(int argc, char *argv[])
{
    string test = "PAYPALISHIRING";
    int numRows = 3;
    Solution solution = Solution();
    string res = solution.convert(test, 3);
    std::cout << res << std::endl;
    return 0;
}