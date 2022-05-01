/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> func(n+1, vector<bool>(m+1, false));
        func[0][0] = true;
        
        for(int i = 0; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(j+1 <= m && p[j+1] == '*') continue;
                if(p[j] != '*')
                {
                    func[i][j] = i && j && func[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                }
                else
                {
                    func[i][j] = (j >= 2 && func[i][j-2]) || (i && j && func[i-1][j] && (s[i]==p[j-1] || p[j-1] == '.'));
                }
            }
        }
        return  func[n][m];
    }
};

int main(int argc, char *argv[])
{
    string s = "aa";
    string p = "a";
    Solution solution = Solution();
    bool res = solution.isMatch(s, p);
    if(res) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

