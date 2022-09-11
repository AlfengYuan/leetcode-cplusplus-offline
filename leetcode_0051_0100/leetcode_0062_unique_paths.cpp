class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> func(m+1, vector<int>(n+1, 1));

        for(int i = 2; i <= m; i++)
        {
            for(int j = 2; j <= n; j++)
            {
                func[i][j] = func[i-1][j] + func[i][j-1];
            }
        }

        return func[m][n];
    }
};