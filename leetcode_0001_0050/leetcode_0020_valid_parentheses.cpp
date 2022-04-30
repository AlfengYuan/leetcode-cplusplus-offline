#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(char c: s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                mystack.push(c);
            }
            else
            {
                if(mystack.empty()) return false;
                if(c == ')' && mystack.top() == '(')
                {
                    mystack.pop();
                }
                else if(c == '}' && mystack.top() == '{')
                {
                    mystack.pop();
                }
                else if(c == ']' && mystack.top() == '[')
                {
                    mystack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(mystack.empty()) return true;
        return false;
    }
};

int main(int argc, char *argv[])
{
    string s = "[({})]";
    Solution solution = Solution();
    bool res = solution.isValid(s);
    if(res) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}