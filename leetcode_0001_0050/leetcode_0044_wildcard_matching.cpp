/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> func(n+1, vector<bool>(m+1));
        func[0][0] = true;

        for(int i = 0; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(p[j] != '*')
                {
                    func[i][j] = i && j && func[i-1][j-1] && (s[i] == p[j] || p[j] == '?');
                }
                else
                {
                    func[i][j] = (j && func[i][j-1]) || (i && func[i-1][j]);
                }
            }
        }
        return func[n][m];
    }
};

int main(int argc, char *argv[])
{
    string s = "aa", p = "a";
    Solution solution = Solution();
    bool result = solution.isMatch(s, p);
    if(result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}