class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int circle = 0;
        for(int i = 1; i <= n*n; i++){
            while(i <= n*n && y < n - circle){
                res[x][y++] = i++;
            }
            y--, x++;

            while(i <= n*n && x < n-circle){
                res[x++][y] = i++;
            }
            x--, y--;

            while(i <= n*n && y >= circle){
                res[x][y--] = i++;
            }
            y++, x--;

            while(i <= n*n && x > circle){
                res[x--][y] = i++;
            }
            x++,y++;

            circle++;
            i--;
        }

        return res;
    }
};