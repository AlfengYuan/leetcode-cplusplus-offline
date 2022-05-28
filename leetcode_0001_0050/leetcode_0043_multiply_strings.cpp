/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        vector<int> res(n+m);

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                int a  = num1[n-i-1] - '0';
                int b  = num2[m-j-1] - '0';
                res[i+j] += a*b;
            }
        }

        for(int i = 0, carry = 0; i < res.size(); i++)
        {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }

        string ans;
        for(int i = res.size() - 1; i>=0; i--)
        {
            if(ans.empty() && res[i] == 0) continue;
            ans += res[i] + '0';
        }

        return ans.empty() ? "0":ans;
    }
};

int main(int argc, char *argv[])
{
    string num1 = "265", num2 = "35";
    Solution solution = Solution();
    string res = solution.multiply(num1, num2);
    cout << res << endl;
    return 0;
}