#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() <= 1) return atoi(tokens[0].c_str());
        stack<int> mystack;
        int result = 0;
        for(string &s: tokens)
        {
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int num1 = mystack.top();
                mystack.pop();
                int num2 = mystack.top();
                mystack.pop();
                if(s == "+")
                {
                    result = (num2 + num1);
                }
                else if(s == "-")
                {
                    result = (num2 - num1);
                }
                else if(s == "*")
                {
                    result = (num2 * num1);
                }
                else if(s == "/")
                {
                    result = (num2 / num1);
                }
                mystack.push(result);

            }
            else
            {
                mystack.push(atoi(s.c_str()));
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<string> tokens =  {"2","1","+","3","*"};
    Solution solution = Solution();
    int result = solution.evalRPN(tokens);
    cout << result << endl;
    return 0;
}