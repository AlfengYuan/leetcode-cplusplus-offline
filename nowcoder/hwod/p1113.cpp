#include <vector>
#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

int n, m;
vector<vector<int>> board;
int ans = 0;

int dfs(int x, int y){
    if(x < 0 || x >= n || y<0 || y>= m) return 0;
    if(board[x][y] != 1) return 0;

    board[x][y] = 0;

    return 1+dfs(x-1, y)
            +dfs(x+1, y) 
            +dfs(x, y-1)
            +dfs(x, y+1);
}

int main(int argc, char *argv[]){
    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m, 0));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] == 1){
                ans = max(ans, dfs(i, j));
            }
        }
    }

    cout << ans << endl;

    return 0;
}