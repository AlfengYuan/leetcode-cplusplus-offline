class Solution {
    vector<vector<int>> origin;
    int m, n;
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        origin = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                update(board, i, j);
            } 
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                board[i][j] = origin[i][j];
            }
        }

    }

    //x-1, y-1; x-1, y; x-1, y+1;
    // x, y-1; x, y+1;
    // x+1, y-1; x+1, y; x+1, y+1;
    void update(vector<vector<int>>& board, int x, int y){
        int zero = 0, one = 0;

        if(x-1 >= 0){
            if(board[x-1][y] == 0) zero++;
            else one++;

            if(y-1 >= 0){
                if(board[x-1][y-1] == 0) zero++;
                else one++;
            }

            if(y+1 < n){
                if(board[x-1][y+1] == 0) zero++;
                else one++;
            }
        }

        if(x+1 < m){
            if(board[x+1][y] == 0) zero++;
            else one++;

            if(y-1 >= 0){
                if(board[x+1][y-1] == 0) zero++;
                else one++;
            }

            if(y+1 < n){
                if(board[x+1][y+1] == 0) zero++;
                else one++;
            }
        }

        if(y-1 >= 0){
            if(board[x][y-1] == 0) zero++;
            else one++;
        }

        if(y+1 < n){
            if(board[x][y+1] == 0) zero++;
            else one++;
        }

        if(board[x][y] == 0){
            if(one==3) origin[x][y] = 1;
        }else{
            if(one==2 || one==3) origin[x][y] = 1;
        }        
    }
};
