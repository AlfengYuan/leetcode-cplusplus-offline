class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> func(m+1, vector<int>(n+1, 0));

        func[1][1] = grid[0][0];
        for(int i = 1; i<=m; i++)
        {
            func[i][1] = func[i-1][1] + grid[i-1][0];
        }

        for(int j = 2; j<= n; j++)
        {
            func[1][j] = func[1][j-1] + grid[0][j-1];
        }

        for(int i = 2; i<=m; i++)
        {
            for(int j = 2; j<=n; j++)
            {
                func[i][j] = min(func[i-1][j],func[i][j-1]) + grid[i-1][j-1];
            }
        }

        return func[m][n];
    }
};