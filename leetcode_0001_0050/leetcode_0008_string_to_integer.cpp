#include <cstring>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i;
        int res = 0;
        for(i = 0; i<s.length(); i++)
        {
            if(s[i] != ' ') break;
        }
        if(s[i] != '+' && s[i] != '-' && !isdigit(s[i])) return 0;

        int flag = 1;
        vector<int> intMin = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7}; // 2^31 -1
        vector<int> resV(0);
        
        if(s[i] == '-') flag = -1;
        if(!isdigit(s[i])) i++;

        while(i < s.length() && isdigit(s[i]) && s[i] == '0') i++; // filter zero from left
        for(; i<s.length(); i++)
        {
            if(!isdigit(s[i])) break;
            resV.push_back(s[i] - '0');
        }

        if(flag == -1) intMin[9] += 1; // 2^31

        if(resV.size() < 10)
        {
            for(i = 0; i<resV.size(); i++)
            {
                res = res * 10 + resV[i];
            }
            return res*flag;
        }
        else if(resV.size() > 10)
        {
            if(flag == -1) return -2147483648;
            else return 2147483647;
        }
        else
        {
            i = 0;
            while(i < 10 && resV[i] == intMin[i]) i++;

            if(i == 10)
            {
                if(flag == -1) return -2147483648;
                else return 2147483647;
            }
            else
            {
                if(resV[i] > intMin[i])
                {
                    if(flag == -1) return -2147483648;
                    else return 2147483647;
                }
                else
                {
                    for(i = 0; i < 10; i++)
                    {
                        res = res * 10 + resV[i];
                    }
                    return res*flag;
                }

            }
        } 
    }
};

int main(int argc, char *argv[])
{
    string s = "-2147483648";
    Solution solution = Solution();
    int res = solution.myAtoi(s);
    cout << res << endl;
    return 0;
}