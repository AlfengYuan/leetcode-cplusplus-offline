/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <stack>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans = 0;
        for(int i = 0, start=-1; i<s.length(); i++)
        {
            if(s[i] == '(') stk.push(i);
            else{
                if(!stk.empty())
                {
                    stk.pop();
                    if(!stk.empty())
                    {
                        ans = max(ans, i-stk.top());
                    }else
                    {
                        ans = max(ans, i-start);
                    }
                }
                else{
                    start = i;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    string s = "(()";
    Solution solution = Solution();
    int res = solution.longestValidParentheses(s);
    cout << res << endl;
    return 0;
}