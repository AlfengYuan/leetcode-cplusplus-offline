#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }

private:
    static void dfs(vector<string> &res, string curr, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(curr);
            return;
        }

        if (right < left) return;
        
        if (left > 0) dfs(res, curr + '(', left-1, right);
        if (right > 0) dfs(res, curr + ')', left, right-1);
    }
};

int main(int argc, char *argv[])
{
    int n = 3;
    Solution solution = Solution();
    vector<string> res = solution.generateParenthesis(3);
    cout << "[";
    for(string &s:res)
    {
        cout << "\"" << s << "\"" << ", ";
    }
    cout << "]" << endl;
    return 0;
}