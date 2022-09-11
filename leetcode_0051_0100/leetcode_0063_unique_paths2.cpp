class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> func(m+1, vector<int>(n+1, 1));

        for(int i = 1; i<=m; i++)
        {
            if(obstacleGrid[i-1][0] == 1)
            { 
                while(i <= m)
                {
                    func[i][1] = 0;
                    i++;
                }
            }   
        }

        for(int i = 1; i<= n; i++)
        {
            if(obstacleGrid[0][i-1] == 1)
            {   while(i <= n)
                {
                    func[1][i] = 0;
                    i++;
                }
            }
        }

        for(int i = 2; i <= m; i++)
        {
            for(int j = 2; j <= n; j++)
            {
                if(obstacleGrid[i-1][j-1] == 1)
                {
                    func[i][j] = 0;
                }
                else
                {
                    func[i][j] = func[i-1][j] + func[i][j-1];
                }
            }
        }

        return func[m][n];

    }
};

