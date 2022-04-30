#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int tmp = num / 1000;
        if(tmp > 0)
        {
            res += string(tmp, 'M');
        }
        num %= 1000;
        tmp = num / 100;
        if(tmp == 9)
        {
            res += "CM";
        }
        else if(tmp > 5)
        {
            res += "D";
            res += string((tmp-5), 'C');
        }
        else if(tmp == 5)
        {
            res += "D";
        }
        else if(tmp == 4)
        {
            res += "CD";
        }
        else if(tmp > 0)
        {
            res += string(tmp, 'C');
           
        }
        num %= 100;
        tmp = num / 10;
        if(tmp == 9)
        {
            res += "XC";
        }
        else if(tmp > 5)
        {
            res += "L";
            res += string((tmp-5), 'X');
        }
        else if(tmp == 5)
        {
            res += "L";
        }
        else if(tmp == 4)
        {
            res += "XL";
        }
        else if(tmp > 0)
        {
            res += string(tmp, 'X');
            
        }
        num %= 10;
        tmp = num / 1;
        if(tmp ==9)
        {
            res += "IX";
        }
        else if(tmp > 5)
        {
            res += "V";
            res += string((tmp-5), 'I');
        }
        else if(tmp == 5)
        {
            res += "V";
        }
        else if(tmp == 4)
        {
            res += "IV";
        }
        else if(tmp > 0)
        {
            res += string(tmp, 'I');
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    int num = 1994;
    Solution solution = Solution();
    string res = solution.intToRoman(num);
    cout << res << endl;
    return 0;
}