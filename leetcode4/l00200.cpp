class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
        
    }

    void dfs(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;

        if(grid[x][y] != '1') return;

        grid[x][y] = '2';

        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
 

    }
};