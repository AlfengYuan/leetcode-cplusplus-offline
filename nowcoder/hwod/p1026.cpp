#include <iostream>
#include <vector>

using namespace std;
int m, n;
int ans = 0;
vector<vector<int>> board;
vector<vector<int>> start;
vector<vector<int>> last;
vector<vector<int>> path1;
vector<vector<int>> path2;
void dfs(int x, int y, vector<vector<int>> &path, int val){
    if(x<0 || x>=m || y<0 || y>=n) return;
    if(board[x][y]==1) return;

    if(path[x][y] != 0) return;

    path[x][y] = val;

    dfs(x-1, y, path, val);
    dfs(x+1, y, path, val);
    dfs(x, y-1, path, val);
    dfs(x, y+1, path, val);
}
int main(int argc, char *argv[]){
    cin >> m >> n;
    board = vector<vector<int>>(m, vector<int>(n, 0));
    path1 = vector<vector<int>>(m, vector<int>(n, 0));
    path2 = vector<vector<int>>(m, vector<int>(n, 0));

    int x;
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> x;
            board[i][j] = x;
            if(x == 2){
                start.push_back({i, j});
            }else if(x==3){
                last.push_back({i, j});
            }
        }
    }

    dfs(start[0][0], start[0][1], path1, 1);
    dfs(start[1][0], start[1][1], path2, 2);

    for(auto &e: last){
        if(path1[e[0]][e[1]] + path2[e[0]][e[1]] == 3){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;

}