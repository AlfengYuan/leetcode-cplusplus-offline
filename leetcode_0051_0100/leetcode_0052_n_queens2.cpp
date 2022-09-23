/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
class Solution {
    vector<bool> col, dg, udg;
    vector<string> path;
    vector<vector<string>> ans;
public:
    int totalNQueens(int n) {
        col = vector<bool>(n);
        dg  = udg = vector<bool>(2 * n);
        path = vector<string>(n, string(n, '.'));
        dfs(0, n);
        return ans.size();

    }

    void dfs(int x, int n)
    {
        if(x==n)
        {
            ans.push_back(path);
            return;
        }

        for(int y = 0; y < n; y++)
        {
            if(col[y] || udg[y-x+n] || dg[y+x]) continue;
            col[y] = udg[y-x+n] = dg[y+x] = true;
            path[x][y] = 'Q';
            dfs(x+1, n);
            path[x][y] = '.';
            col[y] = udg[y-x+n] = dg[y+x] = false;
        }
    }
};