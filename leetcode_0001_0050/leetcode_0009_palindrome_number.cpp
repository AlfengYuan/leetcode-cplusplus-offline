#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<char> resV;
        while(x)
        {
            resV.push_back(x % 10 + '0');
            x /= 10;
        }
        for(int i = 0, j = resV.size()-1; i<=j; ++i, --j)
        {
            if(resV[i] != resV[j]) return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    int x = -121;
    Solution solution = Solution();
    bool res = solution.isPalindrome(x);
    if(res)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}