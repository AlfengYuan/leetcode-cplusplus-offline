#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        else if(n==2) return "11";
        else if(n==3) return "21";
        else if(n==4) return "1211";
        else
        {
            vector<char> alpha = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            string res = "";
            string beforeN = countAndSay(n-1);
            for(int i = 0; i<beforeN.length(); )
            {
                int j, count = 0;
                for(j = 0; j<alpha.size(); ++j)
                {
                    if(beforeN[i] == alpha[j]) break;
                }

                while(i< beforeN.length() && beforeN[i] == alpha[j]) {++count; ++i;}
                res += (count + '0');
                res += alpha[j];
            }
            return res;
        }
    }
};

int main(int argc, char *argv[])
{
    int n = 6;
    Solution solution = Solution();
    string res = solution.countAndSay(n);
    cout << res << endl;
    return 0;
}